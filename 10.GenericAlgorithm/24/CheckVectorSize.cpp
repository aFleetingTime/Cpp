#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;
using std::vector;
using std::string;

bool checkSize(const std::string &s, std::string::size_type size) { return s.size() < size; }

vector<string::size_type>::iterator checkStringsSize(vector<string::size_type> &svec, const string &s)
{
	return std::find_if(svec.begin(), svec.end(), std::bind(checkSize, s, _1));
}

int main()
{
	std::vector<std::string::size_type> svec{ 1, 2, 3, 5, 6, 7, 11 };
	for_each(svec.cbegin(), svec.cend(),
			[](string::size_type size)
			{ std::cout << size << ' '; });
	std::cout << std::endl;

	std::cout << "string: ";
	std::string input;
	std::cin >> input;

	auto target = checkStringsSize(svec, input);
	target == svec.cend() ? std::cout << "容器中没有大于该字符串长度的值" << std::endl : std::cout << "first > string length:" << *target << std::endl;
}
