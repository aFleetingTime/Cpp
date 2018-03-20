#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest)
{
	std::cout << sizeof...(Args) << std::endl;
	std::cout << sizeof...(rest) << std::endl;
}

int main()
{
	std::string s("string");
	foo(0, s, 42, 3.14);
	foo(s, 42, "hi");
	foo(3.14, s);
	foo("hi");
	foo(1, "a", 2, 0.f, 10L);
}
