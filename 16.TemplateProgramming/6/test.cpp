#include "iterator.hpp"
#include <iostream>

int main()
{
	int a[10] { 1,2,3,4,5,6,7,8,9,0 };
	for(int *beg = begin(a); beg != end(a); ++beg)
		std::cout << *beg << std::endl;
}
