#include <iostream>
#include <deque>
#include <algorithm>

using addFunc = void(std::deque<int>::*)(const std::deque<int>::value_type &);

inline void print(const int &i) { std::cout << i << ' '; }

void add(std::deque<int> &ideq, const std::deque<int>::size_type size, addFunc fun)
{
	for(std::deque<int>::size_type i = 0; i < size; (ideq.*fun)(++i));
}

int main()
{
	//Test: 在deque两端插入push元素不会重新分配空间

	std::deque<int> ideq(1, 0);
	auto beg = ideq.cbegin();
	addFunc backfun = &std::deque<int>::push_back;
	addFunc frontfun = &std::deque<int>::push_front;

	add(ideq, 10, backfun);
	std::for_each(ideq.cbegin(), ideq.cend(), print);
	std::cout << "beg = " << *beg << std::endl;

	add(ideq, 10, frontfun);
	std::for_each(ideq.cbegin(), ideq.cend(), print);
	std::cout << "beg = " << *beg << std::endl;
}
