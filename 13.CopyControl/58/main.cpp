#include "Foo.h"

Foo& retLeft() { static Foo ret; return ret; }
Foo retRight() { return Foo(); }

int main()
{
	retRight().sorted();
	std::cout << "-------" << std::endl;
	retLeft().sorted();
}
