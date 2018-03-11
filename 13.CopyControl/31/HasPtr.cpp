#include "HasPtr.h"

HasPtr::HasPtr(const std::string &s, int num) : sp(new std::string(s)), i(num)
{
	;
}

HasPtr::HasPtr(const HasPtr &has) : sp(new std::string(*has.sp)), i(has.i)
{
	;
}

HasPtr& HasPtr::operator=(HasPtr has)
{
	swap(has);
	return *this;
}

HasPtr::~HasPtr()
{
	delete sp;
}

std::string* HasPtr::getSp()
{
	return sp;
}

void HasPtr::swap(HasPtr &has)
{
	using std::swap;
	swap(sp, has.sp);
	swap(i, has.i);
	std::cout << "swap()" << " val1:" << *sp << " val2:" << *has.sp << std::endl;
}

void swap(HasPtr &has1, HasPtr &has2)
{
	has1.swap(has2);
}

bool HasPtr::operator<(const HasPtr &has)
{
	return *sp < *has.sp;
}

const std::string* HasPtr::getSp() const
{
	return sp;
}
