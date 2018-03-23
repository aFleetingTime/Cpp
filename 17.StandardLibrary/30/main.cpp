#include <iostream>
#include <random>
#include <climits>

unsigned myRandom(unsigned min = 0, unsigned max = INT_MAX, unsigned seed = 0)
{
	static std::default_random_engine e(seed);
	static std::uniform_int_distribution<unsigned> u(min, max);
	return u(e);
}

int main()
{
	std::cout << myRandom(5, 10, time(nullptr)) << std::endl;
	std::cout << myRandom() << std::endl;
	std::cout << myRandom() << std::endl;
}
