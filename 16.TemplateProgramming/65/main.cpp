#include <iostream>
#include <string>
#include <sstream>

template <typename T> std::string debugRep(const T &);
template <typename T> std::string debugRep(T *);
template <> std::string debugRep(const char *);
template <> std::string debugRep(char *);
template <> std::string debugRep(const std::string &);

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
template <> std::string debugRep(const char *p) { return debugRep(std::string(p)); }
template <> std::string debugRep(const std::string &s) { return '"' + s + '"'; }
template <> std::string debugRep(char *p) { return debugRep(std::string(p)); }

int main()
{
	char a[] = "aaaaaaaaaaaa";
	char *p = a;
	std::cout << debugRep(p) << std::endl;
	std::cout << debugRep("test") << '\n' << debugRep(std::string("test")) << '\n' << debugRep(100) << '\n' << debugRep(static_cast<int*>(nullptr)) << std::endl;
}
