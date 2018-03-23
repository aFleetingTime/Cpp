#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>

int main()
{
	constexpr unsigned MAX = 200;
	double av = 0, d = 0;
	std::cout << "均值: ", std::cin >> av;
	std::cout << "标准差: ", std::cin >> d;
	std::default_random_engine e;
	std::normal_distribution<> n(av, d);
	std::vector<unsigned> counts(av * 2 + 1);
	for(int i = 0; i != MAX; ++i)
	{
		unsigned val = lround(n(e)); 
		if(val < counts.size())
			++counts[val];
	}
	for(std::size_t i = 0; i != counts.size(); ++i)
		std::cout << i << ": " << std::string(counts[i], '*') << std::endl;
}
