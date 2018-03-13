#include <iostream>
#include <iterator>
#include "StrBlob.h"

struct Test
{
	Test(StrBlobPtr &&p) : ptr(&p) {}
	StrBlobPtr* operator->() { return ptr; }
private:
	StrBlobPtr *ptr;
};

int main()
{
	StrBlob blob { "test" };
	Test t(blob.begin());
	std::cout << t->operator*() << std::endl;
}
