#include "util/random.h"
#include "util/id.h"
#include <iostream>

using namespace branchesdb::util;
using namespace std;

int main() {
    Random random;
    Id id(random);
    cout << random() << endl;
    cout << id << endl;
    Id id2(id);
    cout << id2 << endl;
    id = Id(random);
    cout << id << endl;
    id2 = id;
    cout << id2 << endl;
    return 0;
}
