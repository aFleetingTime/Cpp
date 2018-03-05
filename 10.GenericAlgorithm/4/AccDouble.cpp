#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	std::vector<double> dvec{ 3.14, 3.15, 3.16, 3.17, 3.18 };
	// 由于0默认为int类型，因此sum类型为int，int在与double类型相加时会丢弃小数位
	std::cout << "0 roster = " << std::accumulate(dvec.cbegin(), dvec.cend(), 0) << std::endl;
	// sum为double
	std::cout << "0.0f roster = " << std::accumulate(dvec.cbegin(), dvec.cend(), 0.0f) << std::endl;
}
