#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <regex>

struct PersonInfo
{
	PersonInfo() = default;
	PersonInfo(std::string &&s, std::vector<std::string> &&p) : name(std::move(s)), phones(std::move(p)) { }
	std::string name;
	std::vector<std::string> phones;
};

std::istream& operator>>(std::istream &is, std::vector<PersonInfo> &info)
{
	static std::regex reg("[\\d]+");
	std::string line;
	std::istringstream iformat;
	while(std::getline(is, line))
	{
		iformat.str(line);
		std::string name;
		iformat >> name;
		std::vector<std::string> temp;
		for(std::sregex_iterator beg(line.cbegin(), line.cend(), reg), end; beg != end; ++beg)
			temp.push_back(std::move(beg->str()));
		info.emplace_back(std::move(name), std::move(temp));
		iformat.clear();
	}
}

bool checkPhone(const std::smatch &match)
{
	if(match[1].matched)
		return match[3] == ")";
	return match[3] == match[5] || match[3].str().front() == match[5].str().front();
}

int main(int argv, char **args)
{
	if(argv != 2)
	{
		std::cerr << "./formatInfo <filepath>" << std::endl;
		return -1;
	}
	std::vector<PersonInfo> pinfos;
	std::ifstream input(args[1]);
	if(!input)
	{
		std::cerr << "文件路径无效" << std::endl;
		return -2;
	}
	input >> pinfos;
	std::regex reg("(\\()?(\\d{3})(\\)\\-. )?[ ]*(\\d{3})(-.[ ]*)?(\\d{4,8})");
	std::smatch results;
	for(const auto &info : pinfos)
	{
		std::ostringstream oformat, badNum;
		for(const auto &phone : info.phones)
		{
			if(std::regex_search(phone, results, reg) && checkPhone(results)) oformat << ' ' << phone;
			else badNum << ' ' << phone;
		}
		if(!oformat.str().empty())
			std::cout << info.name << oformat.str() << std::endl;
		if(!badNum.str().empty())
			std::cerr << "姓名:" << info.name << "含有错误格式的号码 -" << badNum.str() << std::endl;
	}
	return 0;
}
