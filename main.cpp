#include "util/id.h"
#include <iostream>

using namespace branchesdb::util;
using namespace std;

int main() {
    cout << Id::generate() << endl;
    return 0;
}
