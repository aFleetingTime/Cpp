#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include <algorithm>

std::shared_ptr<std::vector<int>> getVector() { return std::make_shared<std::vector<int>>(); }

std::shared_ptr<std::vector<int>> inputToVec()
{
	auto retp = getVector();
	std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(*retp));
	return retp;
}

int main()
{
	auto vecp = inputToVec();
	std::copy(vecp->cbegin(), vecp->cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
