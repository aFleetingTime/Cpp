#include <iostream>

struct A
{
	~A() { std::cout << "~A()" << std::endl; }
};

struct B : A
{
	~B() { std::cout << "~A()" << std::endl; }
};

int main()
{
	A *p = new B;
	delete p;
}
