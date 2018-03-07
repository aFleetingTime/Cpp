#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::pair<std::string, int>> pvec;
	std::string input; 
	int num = 0;
	std::cout << "Pair: ";
	while(std::cin >> input >> num)
		pvec.push_back(std::make_pair(input, num));
	std::cout << '\n';
	for(const auto &p : pvec)
		std::cout << "key - " << p.first << "\nvalue - " << p.second << std::endl;
}
