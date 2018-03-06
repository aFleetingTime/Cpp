#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	std::istream_iterator<int> input(std::cin), eof;
	std::vector<int> inputNums(input, eof);
	std::sort(inputNums.begin(), inputNums.end());
	std::unique_copy(inputNums.begin(), inputNums.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
