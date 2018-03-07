#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

int main()
{
	vector<string> svec;
	for(string word; std::cin >> word;)
		if(std::find(svec.cbegin(), svec.cend(), word) == svec.cend())
			svec.push_back(word);
	std::cout << std::endl;
	std::copy(svec.cbegin(), svec.cend(), std::ostream_iterator<string>(std::cout, "\n"));
}
