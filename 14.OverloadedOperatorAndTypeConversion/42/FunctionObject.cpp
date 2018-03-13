#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <random>

using namespace std::placeholders;

int main()
{
	std::vector<std::string> b;
	std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::back_inserter(b));
	std::vector<int> a;
	int(*Stoi)(const std::string&, std::size_t*, int) = std::stoi; 
	std::transform(b.cbegin(), b.cend(), std::back_inserter(a), std::bind(Stoi, _1, nullptr, 0));

	constexpr std::size_t TargetMaxNum = 1024;
	constexpr const char *TargetStr = "pooh";
	std::mt19937 g(1729);
	b.emplace(b.begin() + std::uniform_int_distribution<>(0, b.size())(g), TargetStr);
	std::size_t num = std::count_if(a.cbegin(), a.cend(), std::bind(std::greater<int>(), _1, TargetMaxNum));
	auto index = std::find_if(b.cbegin(), b.cend(), std::bind(std::not_equal_to<std::string>(), _1, TargetStr));
	std::transform(a.cbegin(), a.cend(), a.begin(), std::bind(std::multiplies<int>(), _1, 2));

	;
	std::cout << "(a) " << num << std::endl;
	std::copy(b.cbegin(), b.cend(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << "\n(b) " << (index - b.cbegin()) << std::endl;
	std::cout << "(c) ";
	std::copy(a.cbegin(), a.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
