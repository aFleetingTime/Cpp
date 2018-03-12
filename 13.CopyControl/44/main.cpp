#include <iostream>
#include "String.h"

int main()
{
	String s1 = "aaa";
	String s2(s1);
	std::cout << s1.c_str() << " " << s2.c_str() << std::endl;
	std::cout << s1.size() << " " << s2.size() << std::endl;
	s2 = "test";
	s1 = s2;
	std::cout << s1.c_str() << " " << s2.c_str() << std::endl;
	std::cout << s1.size() << " " << s2.size() << std::endl;
	for(auto &c : s1)
		std::cout << c << ' ';
	std::cout << std::endl;
}
