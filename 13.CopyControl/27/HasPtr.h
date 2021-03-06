#pragma once
#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string(), int num = 0);
	HasPtr(const HasPtr &has);
	HasPtr& operator=(const HasPtr &has);
	~HasPtr();
	std::string* getSp();

private:
	std::string *sp;
	std::size_t *useCount;
	int i;
};
