#include <iostream>
#include "StrVec.h"

int main()
{
	constexpr std::size_t maxSize = 10;
	StrVec svec2(2, "test2");
	for(int i = 0; i < maxSize; ++i)
		svec2.push_back("test2");
	for(int i = 0; i < svec2.size(); ++i)
		std::cout << svec2[i] << std::endl;
}
