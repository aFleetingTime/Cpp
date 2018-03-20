#include "SharedPtr.hpp"
#include "makeShared.hpp"
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
	SharedPtr<std::string> sp = makeShared<std::string>("test");
	std::cout << *sp << std::endl;
}
