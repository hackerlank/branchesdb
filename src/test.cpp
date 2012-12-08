#include "test.h"
#include <cassert>

Test::Test() : counter(0) {}

Test::~Test() {}

Test::Test(const Test& other) : counter(other.counter) {}

Test& Test::operator=(const Test& rhs) {
    if (this == &rhs) {
        return *this;
    }
    counter = rhs.counter;
    return *this;
}
