#include <iostream>
#include <functional>

using namespace std::placeholders;

void func(int a, int b, int c) { std::cout << a << b << c; }

void func(int &a, int &b, int &c) { std::cout << "func&:" << a << b << c; a = 1, b = 2, c = 3; }

int func(int &a) { return ++a; }

template<typename T>
void test(T bindFunc)
{
	for(int i = 0; (i = bindFunc()) != 10; std::cout << "bind num:" << i << std::endl);
}

int main()
{
#if 0
	{
		auto bindFunc = std::bind((void(*)(int,int,int))(func), _2, 10, _1);
		bindFunc(20, 60);
		std::cout << std::endl;
	}
	{
		int a = 0, b = 0, c = 0;
		auto bindFunc = std::bind((void(*)(int&,int&,int&))(func), _2, _1, std::ref(c));
		bindFunc(a, b);
		std::cout << std::endl;
		bindFunc(a, b);
		std::cout << std::endl;
		std::cout << a << b << c << std::endl;
	}
#endif
	int num = 0;
	test(std::bind((int(*)(int&))func, num));
	std::cout << "num value:" << num << std::endl;
	test(std::bind((int(*)(int&))func, std::ref(num)));
	std::cout << "num value:" << num << std::endl;
}
