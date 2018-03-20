#include <iostream>
#include <utility>

template <typename T>
T&& forward(T &obj)
{
	return static_cast<T&&>(obj);
}

template <typename F, typename T1, typename T2>
void flip(F func, T1 &&lhs, T2 &&rhs)
{
	func(forward<T2>(rhs), forward<T1>(lhs));
}

template <typename F, typename T1, typename T2>
void sflip(F func, T1 &&lhs, T2 &&rhs)
{
	func(std::forward<T2>(rhs), std::forward<T1>(lhs));
}

void func(int &&lhs, int &rhs)
{
	std::cout << ++lhs << "  " << ++rhs << std::endl;
}

int main()
{
	int a = 10;
	int b = 20;
	flip(func, a, std::move(b));
	sflip(func, a, std::move(b));
	std::cout << "a: " << a << "  b: " << b << std::endl;
}
