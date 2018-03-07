#include <iostream>
#include <map>
#include <vector>

int main()
{
	std::map<std::string, std::vector<int>> map { {"a", std::vector<int>()} };
	std::map<std::string, std::vector<int>>::iterator iter = map.find("a");
	std::cout << iter->first << std::endl;
}
