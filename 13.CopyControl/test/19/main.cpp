#include <vector>
#include "Employee.h"

int main()
{
	constexpr std::size_t maxSize = 8;
	std::vector<Employee> vec;
	for(int i = 0; i < maxSize; ++i)
	{
		vec.emplace_back("a");
		std::cout << vec.back().getName() << ' ' << vec.back().getID() << std::endl;
	}
	std::cout << vec.back().getName() << ' ' << vec.back().getID() << std::endl;
}
