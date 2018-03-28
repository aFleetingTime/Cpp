#include <iostream>

struct A { virtual ~A() = default; };
struct B : public A { };
struct C : public B { };
struct D : public B, public A { };

int main()
{
	std::cout << std::boolalpha;
	{
		A *pa = new C;
		std::cout << "(a) " << !!dynamic_cast<B*>(pa) << std::endl;
		delete pa;
	}

	{
		B *pb = new B;
		C *pc = dynamic_cast<C*>(pb);
		std::cout << "(b) " << !!pc << std::endl;
		delete pb;
	}

#if 0
	{
		A *pa = new D;
		std::cout << "(c) " << !!dynamic_cast<B*>(pa) << std::endl;
		delete pa;
	}
#endif
	std::cout << std::noboolalpha;
}
