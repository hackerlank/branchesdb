#include "util/id.h"
#include "util/random.h"

using namespace util;
using namespace std;

namespace {
Random numbers;
}

string Id::generate() noexcept {
    //            1          2
    // 01234567 89012345 67890123
    // ------== ====---- --======    0-2 =>   0-3  (map octets 0-2 to chars 0-3)
    // ------== ====---- --======    3-5 =>   4-7
    // 0100--== ====---- 10======    6-8 =>  8-11
    // ------== ====---- --======   9-11 => 12-15
    // ------== ====---- --======  12-14 => 16-19
    // ------==                       15 => 20-21
    //
    //     0: 52  value & 0x3F  (lower 6 bits) (letters only)
    //   1-7: 62  value & 0x3F  (letters and digits)
    //     8: 64  0x10 | (value & 0x03)  (UUID version - random numbers: 0100)
    //     9: 62  value & 0x3F
    //    10: 60  (value & 0x3C) | 0x02  (UUID variant - current standard: 10)
    // 11-20: 62  value & 0x3F
    //    21: 64  value & 0x30 (base 64 zero padded)
    static const char limits[length] = {
        52,  // letters only
        62, 62, 62, 62, 62, 62, 62,  // letters and digits
        64,  // UUID version
        62,
        60,  // UUID variant
        62, 62, 62, 62, 62, 62, 62, 62, 62, 62,
        64  // base 64 zero padded
    };

    static const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    char chars[length];

    numbers.generate(chars, length);

    for (size_t i = 0; i < length; i++) {
        char limit = limits[i];
        char value = chars[i] & 0x3F;
        while (value >= limit) {
            value = numbers() & 0x3F;
        }
        chars[i] = value;
    }

    chars[8] = 0x10 | (chars[8] & 0x03);
    chars[10] = (chars[10] & 0x3C) | 0x02;
    chars[21] = chars[21] & 0x30;

    for (size_t i = 0; i < length; i++) {
        chars[i] = letters[(int)chars[i]];
    }

    return string(chars, length);
}
