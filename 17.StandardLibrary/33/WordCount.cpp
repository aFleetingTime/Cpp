#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

class Words
{
public:
	Words(std::istream &is) { load(is); }
	size_t load(std::istream &is)
	{
		size_t oldSize = wordMap.size();
		for(std::string word; is >> word; ++wordMap[word])
		{
			deletePunc(word);
			toLower(word);
		}
		return wordMap.size() - oldSize;
	}
	void print(std::ostream &os)
	{
		for(auto beg = wordMap.cbegin(), end = wordMap.cend(); beg != end; ++beg)
			os << beg->first << " Count:" << beg->second << std::endl;
	}

private:
	void deletePunc(std::string &s)
	{
		for(std::string::size_type pos = 0; (pos = s.find_first_of(".,~!?/\\+-*/%$#@^&*()")) != s.npos; s.erase(pos, 1));
	}
	void toLower(std::string &s)
	{
		std::transform(s.cbegin(), s.cend(), s.begin(), tolower);
	}
	std::unordered_map<std::string, size_t> wordMap;
};

int main()
{
	Words wordCount(std::cin);
	std::cout << std::endl;
	wordCount.print(std::cout);
}
