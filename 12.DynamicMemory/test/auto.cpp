#include <iostream>
#include <memory>
#include <cstdlib>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

struct Test
{
	~Test() { ++i; std::cout << "~Test()" << std::endl; }
	int i = 0;
};

int main()
{
	kill(getpid(), SIGSEGV);
	auto p = new Test;
	delete p;
	delete p;
	delete p;
	auto p2 = (Test*)malloc(sizeof(Test));
	delete p2;
	delete p2;
	std::cout << p2->i << " " << p->i << std::endl;
#if 0
	std::shared_ptr<Test> sp(new Test);
	auto *p1 = sp.get();
	std::cout << "--------" << std::endl;
	{
		std::shared_ptr<Test> sp2(p1);
	}
	delete p1;
	delete p1;
	delete p1;
	delete p1;
	delete p1;
	sp.reset();
	std::cout << "--------" << std::endl;
#endif
}
