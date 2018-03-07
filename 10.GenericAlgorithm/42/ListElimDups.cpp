#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <list>

void listElimDups(std::list<std::string> &lst)
{
	lst.sort();
	lst.unique();
	lst.sort([](const std::string &s1, const std::string &s2) {
			return s1.size() < s2.size();
	});
}

std::list<std::string>::const_iterator biggies(std::list<std::string> &lst, std::string::size_type size)
{
	listElimDups(lst);
	auto beg = find_if(lst.cbegin(), lst.cend(), [size](const std::string &s) {
		return s.size() >= size;
	});
}

int main()
{
	std::cout << "input: ";
	std::istream_iterator<std::string> in(std::cin), eof;
	std::list<std::string> inputs(in, eof);

	std::cout << "size: ";
	std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.eofbit);
	std::string::size_type size = 0;
	std::cin >> size;

	auto beg = biggies(inputs, size);
	beg == inputs.cend() ? std::cout << "没有符合条件的单词" : std::copy(beg, inputs.cend(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;	
}
