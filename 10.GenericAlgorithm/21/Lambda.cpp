#include <iostream>

int main()
{
	unsigned int num = 10;
	auto lambda = [num]() mutable -> bool { return num > 0 ? --num : num; };
	while(bool b = lambda()) std::cout << std::boolalpha << b << std::endl;
	std::cout << std::boolalpha << lambda() << std::endl;
}
