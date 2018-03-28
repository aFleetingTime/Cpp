//#include "Object.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct B1
{
	B1() { std::cout << "B1" << std::endl; }
};
struct B2
{
	B2() { std::cout << "B2" << std::endl; }
};

struct D1 : virtual public B2, virtual public B1
{
	D1() { std::cout << "D1" << std::endl; }
};
struct D2 : virtual public B1, virtual public B2
{
	D2() { std::cout << "D2" << std::endl; }
};
struct D : public D1, public D2
{
	D() { std::cout << "D" << std::endl; }
};

struct DD : public B1, virtual B2
{
};

void f()
{
	throw;
}

int main()
{
	try {
		try {
			throw 1;
		} catch(...) {
			f();
		}
	} catch(...) {
		std::cout << "e" << std::endl;
	}
}
