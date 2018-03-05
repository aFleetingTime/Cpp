#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

inline std::ostream &print(std::ostream &output, const std::vector<std::string> &svec)
{
       	std::for_each(svec.cbegin(), svec.cend(), [&](const std::string &s) { output << s << ' '; }); 
}

void elimDups(std::vector<std::string> svec)
{
	std::sort(svec.begin(), svec.end());
	std::cout << "sort: ";
	print(std::cout, svec) << std::endl;

	auto endIte = std::unique(svec.begin(), svec.end());
	std::cout << "unique: ";
	print(std::cout, svec) << std::endl;

	svec.erase(endIte, svec.end());
	std::cout << "erase: ";
	print(std::cout, svec) << std::endl;
}

int main()
{
	std::vector<std::string> svec;
	std::cout << "input string:" << std::ends;
	for(std::string input; std::cin >> input; svec.push_back(input));
	elimDups(svec);
}
