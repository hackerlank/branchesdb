#ifndef RANDOM_H
#define RANDOM_H

#include <boost/random/mersenne_twister.hpp>

class Random {
	boost::mt19937 random;

public:
    Random();

private:
    Random(const Random& other);
    Random& operator=(const Random& other);
};

#endif // RANDOM_H
