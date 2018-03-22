#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string input;
	std::regex reg("[^c]ei");
	std::smatch results;
	while(std::cout << ">>> " && std::getline(std::cin, input))
	{
		if(std::regex_search(input, results, reg))
			std::cout << "error: " << results.str() << std::endl;
	}
}
