#include <iostream>
#include <string>
#include <memory>

size_t getSize(const char *p) 
{
	const char *temp = p;
	while(*temp != '\0') ++temp;
	return temp - p;
}

void ctransform(const char *src, char *dest)
{
	while(*src != '\0') *dest++ = *src++;
}

int main()
{
#ifndef STRING
	const char *p1 = "linked string ", *p2 = "test.";
	size_t p1Size = getSize(p1), p2Size = getSize(p2), total = p1Size + p2Size;
	std::unique_ptr<char[]> up(new char[total + 1]{});
	ctransform(p1, up.get());
	ctransform(p1, up.get() + p1Size);
	up[total] = '\0';
	std::cout << up.get() << std::endl;
#else
	std::string s1("linked c++ string "), s2("test");
	std::size_t total = s1.size() + s2.size();
	std::unique_ptr<char[]> up(new char[total + 1]{});
	(s1 + s2).copy(up.get(), std::string::npos);
	up[total] = '\0';
	std::cout << up.get() << std::endl;
#endif
}
