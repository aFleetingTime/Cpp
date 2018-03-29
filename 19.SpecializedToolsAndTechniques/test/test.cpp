#include <new>
#include <iostream>
#include <cstddef>
#include <string>

union Union
{
	char cval;
	int ival;
	long long lval;
	double dval;
};

int main()
{
	Union u;
	std::cout << static_cast<void*>(&u.cval) << '\n'
			  << &u.ival << '\n'
			  << &u.lval << '\n'
			  << &u.dval << std::endl;
}
