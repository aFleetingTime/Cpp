#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "HasPtr.h"

void test(HasPtr p) { std::cout << *p.getSp() << std::endl; }

int main()
{
	srand(time(nullptr));
	constexpr std::size_t maxSize = 5;
	std::vector<HasPtr> vec;
	for(int i = 0; i < maxSize; ++i)
		vec.emplace_back(std::string(1, 'A' + rand() % 26));
	std::for_each(vec.cbegin(), vec.cend(), [](const HasPtr &has) {
		std::cout << *has.getSp() << std::endl;
	});
	std::sort(vec.begin(), vec.end());
	std::for_each(vec.cbegin(), vec.cend(), [](const HasPtr &has) {
		std::cout << *has.getSp() << std::endl;
	});
}
