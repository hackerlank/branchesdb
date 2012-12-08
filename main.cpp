#include <iostream>
#include <boost/array.hpp>
#include "test.h"

using namespace std;

int main() {
    Test test;
    test.setCounter(123);
    cout << test.getCounter() << endl;
    cout << "Hello world!" << endl;
    return 0;
}
