#include <iostream>
#include <string>

class Employee
{
public:
	Employee();
	Employee(const std::string &s);
	const std::string& getName();
	std::size_t getID();

private:
	const std::string name;
	const std::size_t id;
	static std::size_t num;
};
