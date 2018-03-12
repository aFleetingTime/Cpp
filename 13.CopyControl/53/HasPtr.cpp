#include "HasPtr.h"

HasPtr::HasPtr(const std::string &s, int num) : sp(new std::string(s)), i(num), useCount(new std::size_t(1))
{
	;
}

HasPtr::HasPtr(const HasPtr &has) : sp(has.sp), i(has.i), useCount(&(++(*has.useCount)))
{
	;
}

HasPtr::HasPtr(HasPtr &&has) : sp(has.sp), i(has.i), useCount(has.useCount)
{
	has.sp = nullptr;
	has.useCount = new std::size_t(1);
}

#if 1 //ambiguous overload for ‘operator=’ (operand types are ‘HasPtr’ and ‘HasPtr’) 
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
#endif

#if 0
HasPtr& HasPtr::operator=(HasPtr has)
{
	swap(*this, has);
	return *this;
}
#endif

#if 1 //ambiguous overload for ‘operator=’ (operand types are ‘HasPtr’ and ‘std::remove_reference<HasPtr&>::type {aka HasPtr}’)
HasPtr& HasPtr::operator=(HasPtr &&has)
{
	if(this != &has)
	{
		if(!--*useCount)
			delete sp, delete useCount;
		sp = has.sp;
		i = has.i;
		useCount = has.useCount;
		has.sp = nullptr;
		has.useCount = new std::size_t(1);
		std::cout << "move" << std::endl;
	}
}
#endif

HasPtr::~HasPtr()
{
	if(!--*useCount)
		delete sp, delete useCount;
}

std::string* HasPtr::getSp()
{
	return sp;
}

void swap(HasPtr &has1, HasPtr &has2)
{
	using std::swap;
	swap(has1.sp, has2.sp);
	swap(has1.i, has2.i);
}
