#include <iostream>
#include <memory>

struct A
{
	A() = default;
	virtual ~A() = default;
};

struct B : public A { };
struct C : public B { };

int main()
{
	std::unique_ptr<A> pa(new C);
	std::cout << typeid(pa.get()).name() << std::endl;
	C c;
	A &ra = c;
	std::cout << typeid(&ra).name() << std::endl;
	std::unique_ptr<B> px(new B);
	A &r = *px;
	std::cout << typeid(r).name() << std::endl;
}
