#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main()
{
	std::vector<std::unique_ptr<char[]>> vec;
	for(std::string line; std::cout << "line: ", std::getline(std::cin, line); std::cin.ignore(256, '\n'))
	{
		if(!line.size()) continue;
		char *p = new char[line.size() + 2]{};
		std::cout << "char: ";
		p[line.copy(p, line.size())] = std::cin.get();
		p[line.size() + 1] = '\0';
		vec.emplace_back(p);
	}
	std::cout << '\n';
	for(auto &p : vec)
		std::cout << p.get() << std::endl;
}
