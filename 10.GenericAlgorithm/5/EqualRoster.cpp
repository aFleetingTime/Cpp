#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<const char *> roster1{ "abc", "ddd", "test" };
	// 当roster的元素类型为const char *时，比较的是两个指针的值(指向的内存地址)
	std::vector<const char *> roster2{ "abc", "ddd", "test" };    // true
	//std::vector<const char *> roster2{ "zxczcs", "test", "test" }; false
	std::cout << "roster1 == roster2 --- " << std::boolalpha << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << std::endl;	
}
