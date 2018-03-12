#pragma once
#include <memory>
#include <algorithm>

class String
{
	friend void swap(String &, String &);
public:
	String();
	String(const char *);
	String(const String &);
	~String();
	String& operator=(String);
	String& operator=(const char *);

	std::size_t size() const;
	const char* c_str() const;
	char* begin() const;
	char* end() const;

private:
	char *first;
	char *last;
	static std::allocator<char> alloc;

	const char* getEndPoint(const char *p) { while(*p++); return p; }
	void freeMemory();
	std::pair<char*, char*> allocCopyMemory(const char *b, const char *e);
	void setPoint(std::pair<char*, char*>);
};
