#include <iostream>
#include <list>
#include <string>
#include <algorithm>

int main()
{
	std::list<std::string> inputs;
	std::cout << "input:";
	for(std::string indata; std::cin >> indata; inputs.push_back(indata));
	std::cout << "\nnum \"c\" count = " << std::count(inputs.begin(), inputs.end(), "c") << std::endl;
}
