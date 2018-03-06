#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include "elimDups.cpp"

using namespace std::placeholders;

bool checkSize(const std::string &s, std::string::size_type minSize) { return s.size() >= minSize; }

void biggies(std::vector<std::string> &svec, std::string::size_type minSize)
{
	elimDups(svec);
	auto iend = std::stable_partition(svec.begin(), svec.end(), std::bind(checkSize, _1, minSize));
	if(iend == svec.begin())
	{
		std::cout << "null" << std::endl;
		return;
	}
	std::for_each(svec.begin(), iend,
			[](const std::string &s)
		       	{ std::cout << s << ' '; });
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> svec;
	std::string::size_type minSize = 0;

	std::cout << "input:";
	for(std::string input; std::cin >> input; svec.push_back(input));
	std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.eofbit);
	std::cout << "size:";
	std::cin >> minSize;

	biggies(svec, minSize);
}
