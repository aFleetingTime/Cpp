#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string input;
	std::regex reg("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	std::smatch results;
	while(std::cout << ">>> " && std::getline(std::cin, input))
	{
		if(std::regex_search(input, results, reg))
		{
			std::cout << results.str() << '\n' << std::string(results.position(results.size()) - 3, ' ') << '^' << " Error!" << std::endl;
		}
	}
}
