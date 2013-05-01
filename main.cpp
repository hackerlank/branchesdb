#include <cxxabi.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "util/idpool.h"

using namespace util;
using namespace std;

namespace {

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void print_trace() {
    char pid_buf[30];
    sprintf(pid_buf, "%d", getpid());
    char name_buf[512];
    name_buf[readlink("/proc/self/exe", name_buf, 511)]=0;
    int child_pid = fork();
    if (!child_pid) {
        dup2(2,1); // redirect output to stderr
        fprintf(stdout,"stack trace for %s pid=%s\n",name_buf,pid_buf);
        execlp("gdb", "gdb", "--batch", "-n", "-ex", "thread", "-ex", "bt", name_buf, pid_buf, NULL);
        printf("execlp failed");
        abort(); /* If gdb failed to start */
    } else {
        waitpid(child_pid,NULL,0);
    }
}
#endif

void print_backtrace() {
    void *array[10];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace(array, 10);
    strings = backtrace_symbols(array, size);

    //printf("Obtained %zd stack frames.\n", size);

    for (i = 0; i < size; i++)
        printf("%s %lx\n", strings[i], array[i]);

    free(strings);
    printf("\n");

    using namespace abi;

    /** Call-stack entry datastructure. */
	struct entry {
	    /** Default constructor that clears all fields. */
	    entry () : line(0) {
	    }

	    std::string file;     ///< filename
	    size_t      line;     ///< line number
	    std::string function; ///< name of function or method

	    /** Serialize entry into a text string. */
	    std::string to_string () const {
	        std::ostringstream os;
	        os << file << " (" << line << "): " << function;
	        return os.str();
	    }
	};

    // retrieve call-stack
    const int MAX_DEPTH = 20;
    const int num_discard = -1;
    void * trace[MAX_DEPTH];
    int stack_depth = backtrace(trace, MAX_DEPTH);
    std::vector<entry> stack;

    for (int i = num_discard+1; i < stack_depth; i++) {
        Dl_info dlinfo;
        if(!dladdr(trace[i], &dlinfo))
            continue;

        const char * symname = dlinfo.dli_sname;

        int    status;
        char * demangled = abi::__cxa_demangle(symname, NULL, 0, &status);
        if(status == 0 && demangled)
            symname = demangled;

        printf("entry: %s, %s\n", dlinfo.dli_fname, symname);

        // store entry to stack
        if (dlinfo.dli_fname && symname) {
            entry e;
            e.file     = dlinfo.dli_fname;
            e.line     = 0; // unsupported
            e.function = symname;
            stack.push_back(e);
        } else {
            continue; // skip last entries below main
        }

        if (demangled)
            free(demangled);
    }
}

}

int main() {
    for (int i = 0; i < 20; i++) cout << IdPool::get() << endl;
    //print_trace();
    //print_backtrace();
    return 0;
}
