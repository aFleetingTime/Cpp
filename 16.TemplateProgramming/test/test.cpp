#include <iostream>
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
T fcn(T a, T b) { }

int main()
{
	std::shared_ptr<int> p(new int(1), del);
	p.reset(new int(2), del2);
	char &&c = 'c';
	fcn(c, 'c');
	//fcn(1.0, float(1));
}
