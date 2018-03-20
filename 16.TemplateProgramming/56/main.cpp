#include "errorMsg.hpp"

int main()
{
	int a = 10;
	double b = 3.14;
	float c = 5;
	std::string d("test");
	errorMsg(std::cout, a, b, "ctest", c, d) << std::endl;
	errorMsg(std::cout, c, d, a, b, "ctest") << std::endl;
}
