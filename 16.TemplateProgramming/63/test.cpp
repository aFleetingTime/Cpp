#include "count.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> ivec { 1,2,3,8,9,1,5,65,4,5,6,8,48,4 };
	std::vector<double> dvec { 1.25,1.54,5415,54,4545.15,1535.1,1.54 };
	std::vector<const char *> cpvec { "test", "AaaA", "OoO" };
	std::cout << count(ivec, 8) << std::endl;
	std::cout << count(dvec, 1.54) << std::endl;
	std::cout << count(cpvec, "test") << std::endl;
}
