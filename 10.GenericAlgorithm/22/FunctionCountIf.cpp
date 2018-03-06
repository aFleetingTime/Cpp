#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std::placeholders;

inline bool condition(const std::string &s, std::string::size_type size) { return s.size() <= size; }

int main()
{
	std::vector<std::string> svec;
	std::string::size_type size = 0;
	std::cout << "string: ";
	for(std::string input; std::cin >> input; svec.push_back(input));
	std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.eofbit);
	std::cout << "size: ";
	std::cin >> size;
	std::cout << "<= size string count = " << std::count_if(svec.cbegin(), svec.cend(), std::bind(condition, _1, size)) << std::endl;
}
