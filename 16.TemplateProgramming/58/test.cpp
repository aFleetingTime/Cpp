#include <iostream>
#include "Vec.hpp"

int main()
{
	constexpr std::size_t maxSize = 10;
	Vec<std::string> svec(2, "test2");
	Vec<long> ivec;
	for(int i = 0; i < maxSize; ++i)
	{
		svec.emplace_back("test2");
		ivec.push_back(2);
	}
	for(const auto &s : svec)
		std::cout << s << std::endl;
	for(const auto &i : ivec)
		std::cout << i << std::endl;
}
