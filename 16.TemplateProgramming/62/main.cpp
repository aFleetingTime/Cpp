#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <unordered_set>
#include "Sales_item.h"

using namespace std::placeholders;

bool findSales(const Sales_item &item, const std::string isbn) { return item.isbn() != isbn; }

int main()
{
	std::unordered_multiset<Sales_item> salesSet;
	salesSet.emplace();
	salesSet.emplace("test");
	salesSet.emplace("a", 10, 32);
	salesSet.emplace("A", 2);
	for(const auto &val : salesSet)
		std::cout << val << std::endl;
}
