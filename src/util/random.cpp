#include <cstring>
#include <iostream>
#include <fstream>
#include "util/random.h"

using namespace std;

Random::Random() : random() {
    const char* file = "/dev/urandom";

    ifstream stream(file, ios::in | ios::binary);
    if (!stream) {
        throw runtime_error(string("Failed to open file: ") + file);
    }

    typedef boost::mt19937::result_type SeedType;
    const size_t size = random.state_size;
    SeedType seed[size];
    if (!stream.read(reinterpret_cast<char*>(seed), sizeof(seed))) {
        throw runtime_error(string("Failed to read file: ") + file);
    }

    SeedType* begin = seed;
    SeedType* end = seed + size;
    random.seed(begin, end);
}
