#pragma once
#include <cstring>
#include <vector>
#include <iostream>

template <typename T>
unsigned count(const std::vector<T> &vec, typename std::vector<T>::const_reference val)
{
	unsigned ret = 0;
	for(const auto &e : vec)
		if(e == val) ++ret;
	return ret;
}

template <>
unsigned count(const std::vector<const char *> &vec, const char * const &val)
{
	std::cout << "const char *" << std::endl;
	unsigned ret = 0;
	for(const auto &e : vec)
		if(!strcmp(e, val)) ++ret;
	return ret;
}
