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
	using std::swap;
	swap(*this, has);
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

void swap(HasPtr &has1, HasPtr &has2)
{
	using std::swap;
	std::cout << "swap()" << " val1:" << *has1.sp << " val2:" << *has2.sp << std::endl;
	swap(has1.sp, has2.sp);
	swap(has1.i, has2.i);
}
