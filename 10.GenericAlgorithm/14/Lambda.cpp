#include <iostream>

int main()
{
	auto add = [](int a, int b) { return a + b; };
	int a = 0, b = 0;
	std::cin >> a >> b;
	std::cout << add(a, b) << std::endl;
}
