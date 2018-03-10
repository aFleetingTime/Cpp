#include "Employee.h"

int main()
{
	constexpr std::size_t maxSize = 3;
	Employee emps[maxSize] { Employee("e1"), Employee("e2"), Employee() };
	for(auto beg = std::begin(emps); beg != std::end(emps); ++beg)
		std::cout << beg->getName() << ' ' << beg->getID() << std::endl;
}
