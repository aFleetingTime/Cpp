#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> ivec;
	std::cout << "nums: ";
	for(int i = 0; std::cin >> i; ivec.push_back(i));
	std::sort(ivec.begin(), ivec.end());
	std::list<int> ilst;
	std::unique_copy(ivec.cbegin(), ivec.cend(), std::back_inserter(ilst));
	for_each(ilst.cbegin(), ilst.cend(),
			[](const int &i)
			{ std::cout << i << ' '; });
	std::cout << std::endl;
}
