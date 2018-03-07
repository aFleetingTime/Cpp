#include <iostream>
#include <map>

int main()
{
	std::map<int, int> map;
	std::cout << std::boolalpha << (map.lower_bound(1) == map.upper_bound(1)) << std::endl;
#if 0
	std::map<int, int> map{{4, 4}};
	map.insert({1, 1});
	map.insert(map.end(), {2, 2});
	std::cout << "lower: " << map.lower_bound(3)->second << std::endl;
	std::cout << "upper: " << map.upper_bound(3)->second << std::endl;
	for(const auto &pair : map)
		std::cout << pair.first << ' ' << pair.second << std::endl;
#endif
}
