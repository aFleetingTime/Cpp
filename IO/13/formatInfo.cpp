#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

struct PersonInfo
{
	std::string name;
	std::vector<std::string> phones;
};

bool isPhone(const std::string &str)
{
	for(const char &ch : str)
		if(!isdigit(ch))
			return false;
	return true;
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
	std::string line, word;
	std::istringstream iformat;
	while(std::getline(input, line))
	{
		PersonInfo temp;
		iformat.str(line);
		iformat >> temp.name;
		while(iformat >> word)
			temp.phones.push_back(word);
		iformat.clear();
		pinfos.push_back(temp);
	}
	std::ostringstream oformat, badNum;
	for(const auto &info : pinfos)
	{
		for(const auto &phone : info.phones)
		{
			if(isPhone(phone))
				oformat << ' ' << phone;
			else
				badNum << ' ' << phone;
		}
		if(badNum.str().empty())
			std::cout << info.name << oformat.str();
		else
			std::cerr << "姓名:" << info.name << "含有错误格式的号码 -" << badNum.str();
		std::cout << std::endl;
		oformat.clear();
		badNum.clear();
	}
	return 0;
}
