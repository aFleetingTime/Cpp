#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::string;

int main(int args, char *argv[])
{
	if(args != 2)
	{
		std::cerr << "./name <filepath>\n";
		return -1;
	}
	std::ifstream ifs(argv[1]);
	std::istream_iterator<string> input(ifs), inend;
	std::ostream_iterator<string> output(std::cout, " ");
	vector<string> sdata(input, inend);
	std::copy(sdata.cbegin(), sdata.cend(), output);
	std::cout << std::endl;
}
