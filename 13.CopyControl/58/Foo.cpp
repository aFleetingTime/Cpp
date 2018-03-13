#include "Foo.h"

Foo Foo::sorted() &&
{
	sortData();
	std::cout << "&&" << std::endl;
	return *this;
}

Foo Foo::sorted() const &
{
	std::cout << "const &" << std::endl;
#ifdef LEFT
	if(count++ >= 20)
		throw std::runtime_error("无限递归");
	Foo ret(*this);
	return ret.sorted();
#else
	return Foo(*this).sorted();
#endif
}

void Foo::sortData()
{
	std::sort(data.begin(), data.end());
}
