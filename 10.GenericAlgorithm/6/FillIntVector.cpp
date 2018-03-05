#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	std::fill_n(ivec.begin(), ivec.size(), 0);
	for(auto &i : ivec) std::cout << i << ' ';
	std::cout << std::endl;
}
