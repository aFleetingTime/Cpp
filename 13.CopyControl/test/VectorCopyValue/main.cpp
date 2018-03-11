#include <vector>
#include "Employee.h"

int main()
{
	constexpr std::size_t maxSize = 3;
	std::vector<Employee> vec;
	vec.reserve(maxSize);
	for(int i = 0; i < maxSize; ++i)
	{
		vec.emplace_back(std::string(1, 'A' + i));
		std::cout << vec.back().getName() << ' ' << vec.back().getID() << std::endl;
	}
	std::cout << std::endl;
	for(auto &val : vec)
		std::cout << val.getName() << ' ' << val.getID() << std::endl;
}
