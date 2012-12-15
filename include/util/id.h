#ifndef ID_H
#define ID_H

#include <cstring>

namespace branchesdb { namespace util { class Random; } }

namespace branchesdb {
namespace util {

class Id {
public:
	static const std::size_t length = (128 + 5) / 6;  // 22 characters.

	explicit Id(Random& random) noexcept;

	explicit Id(const void* buffer) noexcept {
		memcpy(chars, buffer, length);
		chars[length] = '\0';
	}

	operator const char*() const noexcept {
	    return chars;
	}

private:
	char chars[length + 1];  // Includes room for a terminating null character.
};

}}

#endif // ID_H
