#pragma once
#include <iostream>

template <typename T> std::ostream& print(std::ostream &, const T &);
template <typename T, typename... Args> std::ostream& print(std::ostream &, const T &, const Args&...);

template <typename T> std::ostream& print(std::ostream &os, const T &val) { return os << val; }
template <typename T, typename... Args> std::ostream& print(std::ostream &os, const T &first, const Args&... rest)
{
	os << first << ", ";
	return print(os, rest...);
}
