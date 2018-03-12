#include <iostream>
#include "StrVec.h"

int main()
{
	constexpr std::size_t maxSize = 81689;
	StrVec svec1 = { "test1" };
	StrVec svec2(2, "test2");
	for(int i = 0; i < maxSize; ++i)
		svec2.push_back("test2");
	std::cout << "svec1 size: " << svec1.size() << "  capacity: " << svec1.capacity() << std::endl;
	std::cout << "svec2 size: " << svec2.size() << "  capacity: " << svec2.capacity() << std::endl;
	svec1 = svec2;
	std::cout << "svec1 size: " << svec1.size() << "  capacity: " << svec1.capacity() << std::endl;
	std::cout << "svec2 size: " << svec2.size() << "  capacity: " << svec2.capacity() << std::endl;
	StrVec svec3(svec2);
	std::cout << "svec1 size: " << svec1.size() << "  capacity: " << svec1.capacity() << std::endl;
	std::cout << "svec2 size: " << svec2.size() << "  capacity: " << svec2.capacity() << std::endl;
	std::cout << "svec3 size: " << svec3.size() << "  capacity: " << svec3.capacity() << std::endl;
}
