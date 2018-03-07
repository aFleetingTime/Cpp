#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <cctype>

inline void deletePunc(std::string &s)
{
	for(std::string::size_type pos = 0; (pos = s.find_first_of(".,?!")) != std::string::npos; s.erase(pos, 1));
}

inline void toLower(std::string &s)
{
	std::transform(s.begin(), s.end(), s.begin(), tolower);
}

int main(int args, char *argv[])
{
	if(args != 2)
	{
		std::cerr << "./name <exclude list>\n";
		return -1;
	}
	std::ifstream excludeList(argv[1]);
	if(!excludeList)
	{
		std::cerr << "无访问权限, 或文件不存在！\n";
		return -2;
	}
	std::set<std::string> exclude;
	std::istream_iterator<std::string> in(excludeList), eof;
	std::transform(in, eof, std::inserter(exclude, exclude.begin()), [](std::string word) {
		toLower(word);
		return word;
	});

	std::map<std::string, std::string::size_type> wordsCount;
	std::cout << "Word: ";
	std::istream_iterator<std::string> word_in(std::cin);
	std::for_each(word_in, eof, [&](std::string word) {
		deletePunc(word);
		toLower(word);
		if(exclude.find(word) != exclude.end())
			return;
		std::pair<std::map<std::string, std::string::size_type>::iterator, bool> retp = wordsCount.insert(make_pair(word, 1));
		if(!retp.second)
			++retp.first->second;
	});
	std::cout << '\n';
	for(const auto &word : wordsCount) 
		std::cout << word.first << " count:" << word.second << std::endl;
}
