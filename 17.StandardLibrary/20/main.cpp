#include <iostream>
#include <string>
#include <regex>

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
	while(std::cout << ">>> " && std::getline(std::cin, input))
	{
		bool b = std::regex_search(input, results, reg);
		if(b && checkPhone(results)) std::cout << "valid: " << results.str();
		else if(b) std::cout << "not valid: " << results.str();
		else std::cout << "error not valid: " << input;
		std::cout << std::endl;
	}
}
