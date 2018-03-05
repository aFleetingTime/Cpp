#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

bool partitionPredicate(const std::string &str) { return str.size() >= 5; }

int main()
{
	std::vector<std::string> svec;
	std::cout << "input: ";
	for(std::string input; std::cin >> input; svec.push_back(input));
	auto retEnd = std::partition(svec.begin(), svec.end(), partitionPredicate);
	for_each(svec.begin(), retEnd, [](const std::string &s){ std::cout << s << ' '; });
	std::cout << std::endl;
}
