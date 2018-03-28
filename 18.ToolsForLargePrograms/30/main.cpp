#include <iostream>

struct Class
{
	Class() = default;
	Class(int i) : num(i) { }
	Class(const Class &c) = default;
	virtual ~Class() = default;
	int num = 0;
};
struct Base : public Class
{
	using Class::Class;
	Base(const Base &c) = default;
};
struct D1 : virtual public Base
{
	using Base::Base;
	D1(const D1 &c) = default;
};
struct D2 : virtual public Base
{
	using Base::Base;
	D2(const D2 &c) = default;
};
struct MI : public D1, public D2
{
	using D1::D1;
	using D2::D2;
	MI(int i) : D1(i), D2(i) { }
	MI(const MI &c) = default;
};
struct Final final : public MI, public Class
{
	Final() = default;
	Final(int i) : MI(i), Class(i) { }
	Final(const Final &c) = default;
};

int main()
{
#if 0
	Final f(1);
	MI m;
	D1 d1;
	D2 d2;
	Base b;
	Class c;
#endif
	//Class *cp = new Final(1);	//'Class'  is an ambiguous base of 'Final'
	//delete cp;
	Base *p = new Final(100);
	std::cout << p->num << std::endl;
	delete p;
}
