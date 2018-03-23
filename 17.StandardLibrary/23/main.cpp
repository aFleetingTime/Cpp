#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string input;
	std::regex reg("[\\d]{5}([-])?([\\d]{4})?");
	while(std::getline(std::cin, input))
	{
		for(std::sregex_iterator beg(input.cbegin(), input.cend(), reg), end; beg != end; ++beg)
			if((*beg)[2].matched || !(*beg)[1].matched)
				std::cout << "valid: " << beg->str() << std::endl;
	}
}
