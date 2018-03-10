#include <iostream>
#include "HasPtr.h"

void test(HasPtr p) { std::cout << *p.getSp() << std::endl; }

int main()
{
	HasPtr p1("hasptr");
	HasPtr p2 = p1;
	std::cout << *p2.getSp() << std::endl;
	test(p2);
}
