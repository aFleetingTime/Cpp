#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <algorithm>

constexpr size_t Max = 9;

int main()
{
	std::vector<size_t> src;
	src.reserve(Max);
	for(unsigned i = 0; i < Max; src.push_back(++i));
	
	std::list<size_t> lst;	// 1 ~ 9
	std::copy(src.cbegin(), src.cend(), inserter(lst, lst.begin()));

	std::deque<size_t> frontDeq, backDeq;	// front = 9 ~ 1
											//  back = 1 ~ 9
	std::copy(src.cbegin(), src.cend(), front_inserter(frontDeq));
	std::copy(src.cbegin(), src.cend(), back_inserter(backDeq));

	auto print = [](const size_t &num) { std::cout << num << ' '; };
	std::cout << "insert: ";
	std::for_each(lst.cbegin(), lst.cend(), print);
	std::cout << std::endl;
	std::cout << "front insert: ";
	std::for_each(frontDeq.cbegin(), frontDeq.cend(), print);
	std::cout << std::endl;
	std::cout << "back insert: ";
	std::for_each(backDeq.cbegin(), backDeq.cend(), print);
	std::cout << std::endl;
}
