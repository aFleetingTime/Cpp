#include <iostream>
#include <string>
#include <vector>
#include <memory>

template <typename T>
class C2
{
	template <typename X> friend class Pal2;
};

template <typename T>
class Pal2
{

};

char del(int *p)
{
	delete p;
	return '\0';
}
Pal2<int> del2(int *p)
{
	delete p;
	return Pal2<int>();
}

template <typename T>
void f3(T &&a) 
{
	T b = a;
	if(++b == a)
		std::cout << "==" << std::endl;
}

template <typename T>
void f(const T &a) 
{
	std::cout << a.c_str() << std::endl;
}

int main()
{
#if 0
	std::shared_ptr<int> p(new int(1), del);
	p.reset(new int(2), del2);
	char &&c = 'c';
	fcn(c, 'c');
	//fcn(1.0, float(1));
	int a = 134, b = 1352;
	int &&c = static_cast<int&&>(a);
	f3(b);
#endif
	f(std::string("aaa"));
}
