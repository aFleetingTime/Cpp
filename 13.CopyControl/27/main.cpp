#include <iostream>
#include "HasPtr.h"

void test(HasPtr p) { std::cout << *p.getSp() << std::endl; }

int main()
{
	HasPtr p1("hasptr");
	HasPtr p2 = p1, p3 = p2, p4 = p1;
	p2 = p3;
	p4 = p1;
	p3 = p3;
	std::cout << *p1.getSp() << std::endl;
	test(p3);
}
