#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;
	try {
		std::regex reg(input);
	} catch(std::regex_error err) {
		std::cout << err.what() << '\n' << err.code() << std::endl;
	}
}
