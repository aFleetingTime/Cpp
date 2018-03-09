#include <iostream>
#include <vector>

int main()
{
	const std::vector<int> cvec;
	const std::vector<int> vec;
	std::cout << typeid(cvec.begin()).name() << std::endl;
	std::cout << typeid(vec.begin()).name() << std::endl;
	std::cout << typeid(cvec.cbegin()).name() << std::endl;
	std::cout << typeid(vec.cbegin()).name() << std::endl;
	std::cout << typeid(std::vector<int>::iterator).name() << std::endl;
	std::cout << typeid(std::vector<int>::const_iterator).name() << std::endl;
}
