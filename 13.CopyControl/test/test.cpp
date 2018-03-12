#include <list>
#include <iostream>
#include <vector>
#include <string>

struct Test
{
	Test() = default;
	Test(const Test&) = default;
	Test& operator+(const Test &t) & { std::cout << "&&" << std::endl; return *this; }
	Test& operator=(const Test &t) && { std::cout << "&&" << std::endl; return *this; }
	Test& operator=(const Test &t) & { std::cout << "&" << std::endl; return *this; }
	const Test& operator=(const Test &t) const && { std::cout << "const &&" << std::endl; return *this; }
	const Test& operator=(const Test &t) const & { std::cout << "const &" << std::endl; return *this; }
};

Test& leftVal() { static Test val; return val; }
const Test& cleftVal() { static Test val; return val; }
Test rightVal() { return Test(); }
const Test crightVal() { return Test(); }

int fun() { return 1; }

int f(const int &i) { std::cout << "const &" << std::endl; }
int f(int &i) { std::cout << "&" << std::endl; }

int main()
{
#if 0
	std::list<const char*> lst(10, "aaa");
	std::vector<std::string> vec(lst.cbegin(), lst.cend());
	for(auto &s : vec)
		std::cout << s << std::endl;
	std::cout << std::vector<int>().capacity() << std::endl;
#endif
#if 0
	int &&a = fun();
	const int &b = a;
	f(b);
#endif
#if 0
	Test a, b, c;
	a + b = c;
	leftVal() + leftVal() = rightVal();
#endif
	leftVal() = rightVal();
	cleftVal() = rightVal();
	rightVal() = rightVal();
	crightVal() = rightVal();
}
