#include "Sales_item.h"
#include <vector>
#include <fstream>
//#include "readfile.h"

int main(int argv, char **args)
{
	if(argv <= 1)
	{
		std::cerr << "参数不明确" << std::endl;
		return -1;
	}
	std::vector<Sales_item> items;
	for(int i = 1; i <= argv; ++i)
	{
		std::ifstream input(args[i]);
		if(input)
		{
			do
			{
				Sales_item temp;
				input >> temp;
				if(!items.empty() && temp.isbn() == items.back().isbn())
					items.back() += temp;
				else if(input)
					items.push_back(temp);
			} while(input);
		}
		else
			std::cerr << args[i] << "不存在" << std::endl;
	}
	std::ofstream output("./dest", std::ios::app);
	for(const Sales_item &item : items)
		output << item << std::endl;
	return 0;
}
