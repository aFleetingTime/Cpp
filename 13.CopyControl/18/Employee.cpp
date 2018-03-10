#include "Employee.h"

Employee::Employee() : name("employee" + std::to_string(num)), id(num++) {}
Employee::Employee(const std::string &s) : name(s), id(num++) {}
const std::string& Employee::getName() { return name; }
std::size_t Employee::getID() { return id; }

std::size_t Employee::num = 1000;
