#include "SharedPtr.hpp"
#include <sys/time.h>
#include <iostream>
#include <memory>

class B { };

class D : public B { };

class E : public B { };

void func1(int *p) {
	delete p; 
}
char func2(int *p) {
	delete p; 
}

int main()
{
#if 0
	SharedPtr<int> p(new int(1), func1);
	SharedPtr<int> p3(p);
	p.reset(new int(1), func2);
	SharedPtr<int> p2(p);
	p2.reset(new int(3), func1);
	std::cout << "over" << std::endl;
#endif
#if 0
	SharedPtr<B> p(new D);
	p.reset(new D);
	p.reset(new E);
	p.reset(new B);
#endif
#if 0
	std::shared_ptr<int> p(new int(1), func1);
	std::shared_ptr<int> p3(p);
	p.reset(new int(1), func2);
	std::shared_ptr<int> p2(p);
	p2.reset(new int(3), func1);
	std::cout << "over" << std::endl;
#endif
	struct timeval start, end;
	gettimeofday(&start, nullptr);
	for(int i = 0; i < 1000000; ++i)
#if 0
		SharedPtr<int>(new int(i), func1).reset(new int(i), func2);
#endif
#if 0
		std::shared_ptr<int>(new int(i), func1).reset(new int(i), func2);
#endif
	gettimeofday(&end, nullptr);
	double time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
	std::cout << time << std::endl;
}
