#pragma once
#include <iostream>
#include <string>
#include <sstream>

template <typename T> std::string debugRep(const T &);
template <typename T> std::string debugRep(const T *);
std::string debugRep(const char *);
std::string debugRep(char *);
std::string debugRep(const std::string &);

template <typename T> std::string debugRep(const T &t)
{
	std::ostringstream oss;
	oss << t;
	return oss.str();
}
template <typename T> std::string debugRep(T *p)
{
	std::ostringstream oss;
	oss << "Pointer: " << p << ' ';
	if(p) oss << *p;
	else oss << static_cast<int*>(nullptr);
	return oss.str();
}
std::string debugRep(const std::string &s) { return '"' + s + '"'; }
std::string debugRep(const char *p) { return debugRep(std::string(p)); }
std::string debugRep(char *p) { return debugRep(std::string(p)); }
