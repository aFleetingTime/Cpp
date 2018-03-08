#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <exception>

class WordConversion
{
public:
	using transType = std::unordered_map<std::string, std::string>;
	WordConversion() = default;
	WordConversion(std::istream &transInfoInput, std::ostream &errOutput, std::istream &userInput)
	{
		size_t lineNum = 1;
		for(std::string key, val; transInfoInput >> key; ++lineNum)
		{
			std::getline(transInfoInput, val);
			auto pos = val.find_first_not_of(" ");
			if(pos == std::string::npos)
				throw std::runtime_error(std::string("error: 第") + std::to_string(lineNum) + "行键值对格式错误!");
			val = val.substr(pos);
			auto ret = transMap.emplace(key, val);
			if(!ret.second)
			{
				printWaring(errOutput, ret.first->first, ret.first->second, val);
				char c = getInput(userInput, errOutput);
				if(c == 'y')
					ret.first->second = val;
			}
		}
	}
	void transform(std::istream &textDataInput, std::ostream &formTextOutput)
	{
		for(std::string line; std::getline(textDataInput, line); formTextOutput << '\n')
		{
			std::istringstream inWord(line);
			bool spaceFlag = false;
			for(std::string word; inWord >> word; formTextOutput << transWord(word))
			{
				if(spaceFlag)
				{
					formTextOutput << ' ';
					continue;
				}
				spaceFlag = true;
			}
		}
	}

private:
	const std::string &transWord(const std::string &word)
	{
		auto valueIter = transMap.find(word);
		return valueIter == transMap.end() ? word : valueIter->second;
	}
	void printWaring(std::ostream &errOutput, const std::string &key, const std::string &oldVal, const std::string &newVal)
	{
		errOutput << "检测到有关键字相同的短语。\n关键字:" << key << "\n原短语:" << oldVal << "\n新短语:" << newVal << "\n是否替换? y/n ";
	}
	char getInput(std::istream &userInput, std::ostream &errOutput)
	{
		char c = 0;
		do
		{
			if(c != 0)
				errOutput << "输入错误，请重新输入: ";
			userInput >> c;
			c = tolower(c);
		} while(c != 'y' && c != 'n');
		return c;
	}
	transType transMap;
};

int main(int args, char *argv[])
{
	if(args != 3)
	{
		std::cerr << "./name <dataSrc> <exclude>\n";
		return -1;
	}
	std::ifstream dataSrc(argv[1]), excludeSrc(argv[2]);
	try
	{
		WordConversion wordCon(excludeSrc, std::cerr, std::cin);
		wordCon.transform(dataSrc, std::cout);
	} catch(std::runtime_error &err) {
		std::cerr << err.what() << '\n';
	}
}
