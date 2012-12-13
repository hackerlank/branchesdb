#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>
#include <string>

namespace branchesdb {
namespace util {

class Error : public std::runtime_error {
public:
    explicit Error(const std::string& message);
    virtual ~Error() noexcept;
};

}}

#endif // ERROR_H
