#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cin >> input;
	std::cout << input << std::endl;
	std::getline(std::cin, input);
	std::cout << input << std::endl;
	std::cout << "first char is space ? " << std::boolalpha << (!input.empty() ? input.at(0) == ' ' : false) << std::endl;
}
