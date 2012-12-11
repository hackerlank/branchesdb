#include "util/error.h"

#include <stdexcept>
#include <string>

Error::Error(const std::string& message) : std::runtime_error(message) {}
Error::~Error() noexcept {}
