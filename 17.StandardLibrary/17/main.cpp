#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string input;
	std::regex reg("[[:alpha:]]*[^c]ei[[:alpha:]]*", std::regex::icase);
	while(std::cout << ">>> " && std::getline(std::cin, input))
	{
		for(std::sregex_iterator beg(input.cbegin(), input.cend(), reg), end; beg != end; ++beg)
		{
			auto pos = beg->prefix().length();
			pos = pos > 10 ? pos - 10 : 0;
			std::cout << beg->prefix().str().substr(pos) << "\033[31m" << beg->str() << "\033[0m" << beg->suffix().str().substr(0, 10) << std::endl;
		}
	}
}
