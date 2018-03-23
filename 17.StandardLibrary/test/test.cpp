#include <tuple>
#include <bitset>
#include <vector>
#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>

std::vector<unsigned> random(std::size_t size)
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u;
	std::vector<unsigned> ret;
	for(std::size_t i = 0; i < size; ++i)
		ret.push_back(u(e));
	return ret;
}

int main()
{
#if 0
	std::bitset<32> bits;
	std::cin >> bits;
	std::cout << (bits ^ std::bitset<32>(0xFFFFFFFF)) << std::endl;
	int a[2] { 0, 1 };
	auto [x, y] = a;
	auto v = std::vector { 1,2,3,4,5 };
	std::vector l{ 1,2,3,4,5 };
#endif
#if 0
	std::ostream_iterator<unsigned> beg(std::cout, "\n");
	std::vector<unsigned> vec1 = random(5);
	std::vector<unsigned> vec2 = random(5);
	std::copy(vec1.cbegin(), vec1.cend(), beg);
	std::copy(vec2.cbegin(), vec2.cend(), beg);
#endif
#if 0
	std::default_random_engine e1(1);
	std::default_random_engine e2(2);
	e2();
	std::cout << e1() << "  " << e2() << std::endl;
#endif
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u;
	while(1)
	{
		e.seed(0);
		std::cout << u(e) << std::endl;
	}
}
