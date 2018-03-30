#include <new>
#include <iostream>
#include <cstddef>
#include <string>
#include <typeinfo>
#include <functional>
#include <random>

struct B {
	virtual ~B() = default;
};
struct D1 : B {
	virtual ~D1() = default;
};
struct D2 : B{
	virtual ~D2() = default;
};

union U {
	U() { }
	~U() { }
	U& operator=(const U &) { }
	int i;
	std::string s;
};

bool fun() {
	return true;
}

int main()
{
#if 0
	U u1, u2;
	u1.i = 1;
	new (&u2.s) std::string("test");
	std::cout << u1.i << "  " << u2.s << std::endl;
	new (&u1.s) std::string(u2.s);
	std::cout << u1.s << "  " << u2.s << std::endl;
	u1.s.~basic_string();
	u2.s.~basic_string();
	u1.i = 10;
	u2.i = u1.i;
	std::cout << u1.i << "  " << u2.i << std::endl;
	std::cout << std::not_fn(fun)() << std::endl;
#endif
	//std::random_device dev;
	std::seed_seq seq();
	std::default_random_engine e(seq);
	std::uniform_int_distribution<unsigned> uid(1, 100);
	std::cout << uid(e) << std::endl;
	//std::cout << uid((unsigned)dev()) << std::endl;
	//std::cout << uid(dev()) << ' ' << uid(dev()) << ' ' << uid(dev()) << std::endl;
}
