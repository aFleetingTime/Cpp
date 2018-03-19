#include <iostream>
#include <vector>
#include "for_each.hpp"

int main()
{
	std::vector<int> ivec { 1,2,3,4,5,6,7,8,9,0 };
	for_each(ivec, [](const int &i) { std::cout << i << std::endl; });
}
