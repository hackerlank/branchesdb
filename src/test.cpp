#include "test.h"

Test::Test() {
    counter = 0;
}

Test::~Test() {
    //dtor
}

Test::Test(const Test& other) {
    //copy ctor
}

Test& Test::operator=(const Test& rhs) {
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
