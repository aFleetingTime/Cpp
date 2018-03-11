#include <list>
#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::list<const char*> lst(10, "aaa");
	std::vector<std::string> vec(lst.cbegin(), lst.cend());
	for(auto &s : vec)
		std::cout << s << std::endl;
}
