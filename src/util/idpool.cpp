#include "util/id.h"
#include "util/idpool.h"

using namespace std;
using namespace util;

string IdPool::get() noexcept {
    return Id::generate();
}
