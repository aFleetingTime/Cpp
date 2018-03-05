#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> inputs;
	std::cout << "input:";
	for(int num = 0; std::cin >> num; inputs.push_back(num));
	std::cout << "num 66 count = " << std::count(inputs.begin(), inputs.end(), 66) << std::endl;
}
