#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimDups(std::vector<std::string> &svec)
{
	std::sort(svec.begin(), svec.end());
	svec.erase(std::unique(svec.begin(), svec.end()), svec.end());
	std::stable_sort(svec.begin(), svec.end(),
		       	[](const std::string &s1, const std::string &s2)
		       	{ return s1.size() < s2.size(); });
#ifndef NDEBUG
	std::for_each(svec.begin(), svec.end(), 
			[](const std::string &s)
		       	{ std::cout << s << ' '; });
	std::cout << std::endl;
#endif
}

void biggies(std::vector<std::string> &svec, std::string::size_type minSize)
{
	elimDups(svec);
	auto first = std::find_if(svec.cbegin(), svec.cend(),
			[minSize](const std::string &s)
			{ return s.size() >= minSize; });
	if(first == svec.cend())
	{
		std::cout << "null" << std::endl;
		return;
	}
	std::for_each(first, svec.cend(), 
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
