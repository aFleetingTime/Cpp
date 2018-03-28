#include <iostream>
#include <string>
#include <regex>

struct Base { virtual ~Base() = default; };
struct Derived : public Base { virtual ~Derived() override = default; };

std::string trans(const std::string &s)
{
	static std::regex reg("([A|P])?([0-9]*)_?([\\w]*)"); //([[:alpha:]]*));
	std::smatch results;
	std::regex_match(s, results, reg);
	std::string ret;
	if(results[1].matched) 
	{
		char c = results[1].str().front();
		if(c == 'A') ret += "Array ";
		else if(c == 'P') ret += "Pointer ";
	}
	if(results[2].length() && results[3].matched) 
		ret += results.format("size:$2 type:$3");
	else if(results[3].matched)
		ret += "type:" + results[3].str();
	return ret;
}

int main()
{
	int arr[10]{};
	Derived d;
	Base *p = &d;
	std::string *sp = nullptr;

	std::cout << trans(typeid(42).name()) << '\n'
			  << trans(typeid(arr).name()) << '\n'
			  << trans(typeid(std::string).name()) << '\n'
			  << trans(typeid(p).name()) << '\n'
			  << trans(typeid(*p).name()) << '\n'
			  << trans(typeid(sp).name()) << std::endl;
	std::cout << trans("A10_int") << std::endl;
}
