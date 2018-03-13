#include <iostream>
#include <vector>
#include "String.h"

int main()
{
	std::vector<String> svec;
	for(int i = 0; i < 10; ++i)
		svec.emplace_back("test");
	for(const String &str : svec)
		std::cout << str << std::endl;
}
