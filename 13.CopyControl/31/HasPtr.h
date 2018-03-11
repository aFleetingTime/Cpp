#pragma once
#include <string>
#include <iostream>

class HasPtr
{
	friend void swap(HasPtr &, HasPtr &);

public:
	HasPtr(const std::string &s = std::string(), int num = 0);
	HasPtr(const HasPtr &has);
	HasPtr& operator=(HasPtr has);
	~HasPtr();
	bool operator<(const HasPtr &has);
	std::string* getSp();
	const std::string* getSp() const;
	void swap(HasPtr &has);

private:
	std::string *sp;
	std::size_t *useCount;
	int i;
};
