#include <iostream>
#include "StrBlob.h"

int main()
{
	StrBlob blob { "first" };
	for(int i = 0; i < 100; ++i)
		blob.push_back("test");
	blob.push_back("last");
	for(auto beg = blob.begin(); beg != blob.end(); ++beg)
		std::cout << *beg << std::endl;
}
