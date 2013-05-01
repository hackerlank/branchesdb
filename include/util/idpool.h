#ifndef IDPOOL_H
#define IDPOOL_H

#include <string>

namespace util {

class IdPool {
public:
    static std::string get() noexcept;
};

}

#endif // IDPOOL_H
