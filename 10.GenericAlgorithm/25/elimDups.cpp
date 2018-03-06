#pragma once

void elimDups(std::vector<std::string> &svec)
{
	std::sort(svec.begin(), svec.end());
	svec.erase(std::unique(svec.begin(), svec.end()), svec.end());
	std::stable_sort(svec.begin(), svec.end(),
		       	[](const std::string &s1, const std::string &s2)
		       	{ return s1.size() < s2.size(); });
#ifndef NDEBUG
	std::for_each(svec.begin(), svec.end(), 
			[](const std::string &s)
		       	{ std::cout << s << ' '; });
	std::cout << std::endl;
#endif
}
