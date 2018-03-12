#include <iostream>
#include "HasPtr.h"

void test(HasPtr p) { std::cout << *p.getSp() << std::endl; }

int main()
{
	HasPtr p1("hasptr");
	HasPtr p2 = p1, p3 = p2, p4("hello"), p5("test"), p6(std::move(p4));
	p2 = std::move(p5);
	p4 = p1;
	p3 = p3;
	std::cout << *p1.getSp() << std::endl;
	test(p2);
	std::cout << *p6.getSp() << std::endl;
}
