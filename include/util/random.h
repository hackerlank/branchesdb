#ifndef RANDOM_H
#define RANDOM_H

#include <boost/random/mersenne_twister.hpp>

namespace branchesdb {
namespace util {

// Random number generator. Uses the Mersenne Twister algorithm. This algorithm
// has excellent randomness qualities (if initialized properly). It does not
// provide cryptographically secure randomness, though (e.g., given the same
// initial seed, it will generate the same sequence of random numbers).
//
// The internal state is initialized using /dev/urandom. This is platform
// dependent, mostly available on unix-based systems (i.e., it's not available
// on Windows). The entire state vector is seeded. This helps ensures a random
// starting point.
//
// This is a large object. It consumes 2K+ bytes of memory.
class Random {
public:
    Random();

	uint32_t operator()() {
		return random();
	}

	void generate(char* buffer, std::size_t count) {
		random.generate(buffer, buffer + count);
	}

private:
    Random(const Random& other);
    Random& operator=(const Random& other);

private:
	boost::mt19937 random;
};

}}

#endif // RANDOM_H
