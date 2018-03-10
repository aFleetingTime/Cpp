#pragma once
#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string(), int num = 0) : sp(new std::string(s)), i(num) {}
	HasPtr(const HasPtr &has) : sp(new std::string(*has.sp)), i(has.i) {}
	~HasPtr() { delete sp; }
	std::string* getSp() { return sp; }

private:
	std::string *sp;
	int i;
};
