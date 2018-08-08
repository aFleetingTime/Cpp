#include <iostream>
#include <string>
#include <forward_list>

size_t eraseString(std::forward_list<std::string> &sflist, const std::string &str, const std::string dest)
{
	auto curr = sflist.cbegin();
	size_t sCount = 0;
	while(curr != sflist.cend())
		if(*curr == str)
			(curr = ++sflist.insert_after(curr, dest)), ++sCount;
		else ++curr;
	if(!sCount)
		sflist.push_front(dest);
	return sCount;
}

int main()
{
	std::forward_list<std::string> sflist = { "aaaaa", "bbbbb", "aaaaa", "ccccc", "aaaaa" };
	eraseString(sflist, "aaaaa", "ddddd");
	for(const std::string &str : sflist) std::cout << str << std::endl;
}
