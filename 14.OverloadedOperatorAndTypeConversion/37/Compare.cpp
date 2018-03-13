#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

struct Compare
{
	Compare(const std::string s) : repStr(s) {}
	bool operator()(const std::string s) { return s == repStr; }
private:
	std::string repStr;
};

struct PrintString
{
	PrintString(std::ostream &os = std::cout, char c = ' ') : out(os), sep(c) {}
	std::ostream& operator()(const std::string s) { out << s << sep; return out; }
	void operator()(std::vector<std::string>::const_iterator beg, std::vector<std::string>::const_iterator end)
	{
		while(beg != end)
			out << *beg++ << sep;
	}
private:
	std::ostream &out;
	char sep;
};

struct GetLineString
{
	GetLineString(std::istream &is = std::cin) : in(is) {}
	std::string operator()() { std::string temp; std::getline(in, temp); return temp; }
	void operator()(std::back_insert_iterator<std::vector<std::string>> beg)
	{
		for(std::string line; std::getline(in, line); *beg = line);
		std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.eofbit);
	}
private:
	std::istream &in;
};

int main()
{
	std::vector<std::string> svec;
	std::cout << "string:" << std::endl;
	GetLineString getLine;
	getLine(std::back_inserter(svec));
	std::cout << "\nreplace string:" << std::endl;
	std::string str = getLine();
	std::replace_if(svec.begin(), svec.end(), Compare(str), "Test");
	std::cout << '\n';
	PrintString(std::cout, '\n')(svec.cbegin(), svec.cend());
}
