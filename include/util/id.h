#ifndef ID_H
#define ID_H

#include <string>

namespace util {

class Id {
public:
	static const std::size_t length = (128 + 5) / 6;  // 22 characters.
    static std::string generate() noexcept;
};

}

#endif // ID_H
