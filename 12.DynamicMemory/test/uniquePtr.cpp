#include <iostream>
#include <memory>

int main()
{
	std::cout << sizeof(std::unique_ptr<long long>) << std::endl;
	std::cout << sizeof(std::auto_ptr<long long>) << std::endl;
}
