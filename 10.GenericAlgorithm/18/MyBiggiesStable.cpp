#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "elimDups.cpp"

void biggies(std::vector<std::string> &svec, std::string::size_type minSize)
{
	elimDups(svec);
	auto first = std::stable_partition(svec.begin(), svec.end(),
			[minSize](const std::string &s)
			{ return s.size() < minSize; });
	if(first == svec.cend())
	{
		std::cout << "null" << std::endl;
		return;
	}
	std::for_each(first, svec.end(), 
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
