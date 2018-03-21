#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "SalesItem.h"

using Srs = std::vector<std::vector<SalesItem>>;

void reportResults(std::istream &is, std::ostream &os, const std::vector<std::vector<SalesItem>> &files)
{
	std::string inputBook;
	while(os << ">>> " && is >> inputBook)
	{
		std::vector<Matches> trans = findBook(files, inputBook);
		if(trans.empty())
		{
			std::cout << "该书籍销售记录为空..." << std::endl;
			continue;
		}
		os << "isbn: " << inputBook << std::endl;
		for(const Matches &t : trans)
			os << "store: " << std::get<0>(t) << " sales: " << std::accumulate(std::get<1>(t), std::get<2>(t), SalesItem(inputBook)) << std::endl;
	}
}

int main()
{
	Srs files;
	for(int i = 0; i < 10; ++i)
		files.push_back({{"BOOK", 5, 6}});
	files.push_back({{"B", 10, 15}});
	files.back().emplace_back("BOOK", 5, 6);
	reportResults(std::cin, std::cout, files);
}
