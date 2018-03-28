#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <ctime>

std::size_t myCount(const std::vector<std::string> &vec)
{
	return std::count_if(vec.cbegin(), vec.cend(), std::mem_fn(&std::string::empty));
}

int main()
{
	std::default_random_engine e(time(nullptr));
	std::uniform_int_distribution<unsigned> rand(0, 1);
	std::vector<std::string> vec;
	for(std::size_t i = 0; i < 100; ++i)
		vec.emplace_back(rand(e), '*');
	std::cout << myCount(vec) << std::endl;
}
