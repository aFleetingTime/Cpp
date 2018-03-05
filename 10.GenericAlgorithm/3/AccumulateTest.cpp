#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main()
{
	std::vector<int> ivec = { 1, 15, 98, 41, 454 };
	std::vector<std::string> svec = { "aaa", "bbb", "ccc" };
	std::cout << "int sum = " << std::accumulate(ivec.cbegin(), ivec.cend(), 0) << std::endl;
	std::cout << "string sum = " << std::accumulate(svec.cbegin(), svec.cend(), std::string("")) << std::endl;
}
