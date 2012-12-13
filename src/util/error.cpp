#include "util/error.h"
#include <stdexcept>
#include <string>

using namespace branchesdb::util;
using namespace std;

Error::Error(const string& message) : runtime_error(message) {}
Error::~Error() noexcept {}
