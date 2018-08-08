#include <iostream>
#include <forward_list>

void eraseOdd(std::forward_list<int> &flst)
{
	auto curr = flst.cbegin(), prev = flst.cbefore_begin();
	while(curr != flst.cend())
		(*curr % 2) ? curr = flst.erase_after(prev) : prev = curr++;
}

int main()
{
	std::forward_list<int> flst = { 1, 3, 4, 6, 8, 9, 11 };
	eraseOdd(flst);
	for(auto &val : flst) std::cout << val << ' ';
	std::cout << std::endl;
}
