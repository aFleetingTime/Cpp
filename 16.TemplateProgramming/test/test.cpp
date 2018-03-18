#include <iostream>

template <typename T>
class C2
{
	template <typename X> friend class Pal2;
};

template <typename T>
class Pal2
{

};

int main()
{
	C2<int> c;
}
