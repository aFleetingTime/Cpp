#include "Employee.h"
#include <iostream>

Employee::Employee() : name("employee" + std::to_string(num)), id(num) { ++num; }

Employee::Employee(const std::string &s) : name(s), id(num) { ++num; }

const std::string& Employee::getName() { return name; }

std::size_t Employee::getID() { return id; }

std::size_t Employee::num = 1000;

Employee::Employee(const Employee &emp) : name(emp.name), id(num) { ++num; }
