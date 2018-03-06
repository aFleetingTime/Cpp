#include <iostream>

int main()
{
	int a = 0, b = 0;
	std::cin >> a >> b;
	auto add = [a](int b) { return a + b; };
	std::cout << add(b) << std::endl;
}
