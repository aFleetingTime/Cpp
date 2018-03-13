#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

class Count
{
public:
	Count(std::map<std::size_t, std::size_t> &cnt, std::map<std::size_t, std::size_t> &mcnt, std::size_t mn, std::size_t mx) : count(cnt), maxCount(mcnt), min(mn), max(mx) {}
	bool operator()(const std::string &s)
	{
		bool b = min <= s.size() && s.size() <= max;
		if(b) ++count[s.size()];
		else ++maxCount[s.size()];
		return b;
	}
private:
	std::map<std::size_t, std::size_t> &count, &maxCount;
	std::size_t min, max;
};

int main()
{
	std::map<std::size_t, std::size_t> count, maxCount;
	std::for_each(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), Count(count, maxCount, 1, 9));
	for(auto p : count)
		std::cout << "length " << p.first << " string  Count:" << p.second << std::endl;
	std::cout << "-------------" << std::endl;
	for(auto p : maxCount)
		std::cout << "length " << p.first << " string  Count:" << p.second << std::endl;
}
