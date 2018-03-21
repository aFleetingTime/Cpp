#include <tuple>
#include <iostream>

int main()
{
	std::tuple<int, int, int> tp1(1, 1, 3);
	std::tuple<int, int, int, int> tp2(1, 2, 2, 3);
	std::cout << (tp1 < tp2) << std::endl;
}
