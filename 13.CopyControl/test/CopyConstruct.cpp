#include <iostream>

class Test
{
public:
	Test(int num) : a(num)
	{
		std::cout << "Test()" << std::endl;
	}
	int a;
	Test(const Test &t) : a(t.a)
	{
		std::cout << "copy Test()" << std::endl;
	}
	Test& operator=(Test &t)
	{
		a = t.a;
	}
};

int main()
{
	Test t = 1;
	Test *a = new Test(t);
	*a = t;
	delete a;
	std::cout << t.a << std::endl;
}
