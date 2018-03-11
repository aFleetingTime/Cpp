#include "HasPtr.h"

HasPtr::HasPtr(const std::string &s, int num) : sp(new std::string(s)), i(num), useCount(new std::size_t(1))
{
	;
}

HasPtr::HasPtr(const HasPtr &has) : sp(has.sp), i(has.i), useCount(&(++(*has.useCount)))
{
	;
}

HasPtr& HasPtr::operator=(const HasPtr &has)
{
	++*has.useCount;
	if(!--*useCount)
		delete sp, delete useCount;
	useCount = has.useCount;
	sp = has.sp;
	i = has.i;
	return *this;
}

HasPtr::~HasPtr()
{
	if(!--*useCount)
		delete sp, delete useCount;
}

std::string* HasPtr::getSp()
{
	return sp;
}
