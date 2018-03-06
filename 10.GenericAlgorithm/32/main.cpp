#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include "Sales_item.h"

using namespace std::placeholders;

bool findSales(const Sales_item &item, const std::string isbn) { return item.isbn() != isbn; }

int main()
{
	std::istream_iterator<Sales_item> input(std::cin), eof;
	std::vector<Sales_item> salesVec(input, eof);
	std::sort(salesVec.begin(), salesVec.end(), compareIsbn);
	for(auto beg = salesVec.cbegin(), last = beg ,end = salesVec.cend(); beg != end; beg = last)
	{
		last = std::find_if(beg, end, std::bind(findSales, _1, beg->isbn()));
		std::cout << std::accumulate(beg, last, Sales_item(beg->isbn())) << std::endl;
	}
}
