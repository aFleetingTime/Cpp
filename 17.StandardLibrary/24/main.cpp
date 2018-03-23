#include <iostream>
#include <string>
#include <regex>

using namespace std::regex_constants;

bool checkPhone(const std::smatch &match)
{
	if(match[1].matched)
		return match[3] == ")";
	return match[3] == match[5];
}

int main()
{
	std::string input;
	std::string pattern("(\\()?(\\d{3})([\\).\\- ])?[ ]?(\\d{3})([.\\- ])?(\\d{4,8})");
	std::regex reg(pattern);
	std::smatch results;
	std::cout << ">>> ";
	while(std::getline(std::cin, input))
		std::cout << std::regex_replace(input, reg, "$2-$4-$6  ", format_no_copy | format_first_only) << std::endl;
}
