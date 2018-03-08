#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<int>* getVector() { return new std::vector<int>; }

std::vector<int>* inputToVec()
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
	delete vecp;
}
