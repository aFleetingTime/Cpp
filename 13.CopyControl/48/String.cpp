#include "String.h"

std::allocator<char> String::alloc;

String::String() : String("") {}

String::String(const char *cstr)
{
	setPoint(allocCopyMemory(cstr, getEndPoint(cstr)));
	std::cout << "String(char*) " << first << std::endl;
}

String::String(const String &str)
{
	setPoint(allocCopyMemory(str.begin(), str.end()));
	std::cout << "String(String&) " << first << std::endl;
}

String::String(String &&str) noexcept : first(str.first), last(str.last)
{
	str.first = str.last = nullptr;
	std::cout << "String(String&&) " << first << std::endl;
}

String& String::operator=(String str)
{
	swap(*this, str);
	std::cout << "= operator(String) " << first << std::endl;
	return *this;
}

String& String::operator=(const char *cstr)
{
	auto flp = allocCopyMemory(cstr, getEndPoint(cstr));
	freeMemory();
	first = flp.first, last = flp.second;
	std::cout << "= operator(char*) " << first << std::endl;
	return *this;
}

String::~String()
{
	freeMemory();
	first = nullptr, last = nullptr;
}

std::size_t String::size() const
{
	return last - first;
}

char* String::begin() const
{
	return first;
}

char* String::end() const
{
	return last;
}

const char* String::c_str() const
{
	return begin();
}

std::pair<char*, char*> String::allocCopyMemory(const char *b, const char *e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void String::freeMemory()
{
	if(!first)
		return;
	std::for_each(first, last, [this](const char &c) { alloc.destroy(&c); });
	alloc.deallocate(first, last - first);
}

void swap(String &s1, String &s2)
{
	using std::swap;
	swap(s1.first, s2.first);
	swap(s1.last, s2.last);
}

void String::setPoint(std::pair<char*, char*> flp)
{
	first = flp.first, last = flp.second;
}
