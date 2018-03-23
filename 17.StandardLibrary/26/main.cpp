#include <iostream>
#include <string>
#include <regex>

using namespace std::regex_constants;

bool checkPhone(const std::smatch &match)
{
	if(match[1].matched)
		return match[3] == ")";
	return match[3] == match[5];
}

int main()
{
	std::string input;
	std::string pattern("(\\()?(\\d{3})([\\).\\- ])?[ ]?(\\d{3})([.\\- ])?(\\d{4,8})");
	std::regex reg(pattern);
	std::smatch results;
	std::cout << ">>> ";
	std::string fmt("$2-$4-$6");
	while(std::getline(std::cin, input))
	{
#if 0
		bool pflag = false, fflag = true;
		std::string first;
		for(std::sregex_iterator beg(input.cbegin(), input.cend(), reg), end; beg != end; ++beg)
			if(pflag) std::cout << beg->format(fmt) << "  ", fflag = false;
			else pflag = true, first = beg->format(fmt);
		if(fflag)
			std::cout << first;
		std::cout << std::endl;
#endif
		std::deque<std::smatch> deq(std::sregex_iterator(input.cbegin(), input.cend(), reg), std::sregex_iterator());
		if(deq.size() == 1)
			std::cout << deq.front().format(fmt);
		else
		{
			deq.pop_front();
			for(const auto &match : deq)
				std::cout << match.format(fmt) << "  ";
		}
		std::cout << std::endl;
	}
}
