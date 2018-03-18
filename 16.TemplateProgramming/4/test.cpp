#include <iostream>
#include <string>
#include <vector>
#include "find.hpp"

int main()
{
	std::vector<int> ivec { 45,6,8,4,89,45,6,45,6,41,53,4,56,8,9 };
	std::vector<std::string> svec { "a", "b", "eee", "rty", "q" };
	std::cout << *find(ivec.cbegin(), ivec.cend(), 41) << std::endl;
	std::cout << *find(svec.cbegin(), svec.cend(), "rty") << std::endl;
}
