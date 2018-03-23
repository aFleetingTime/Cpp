#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <exception>
#include <random>
#include <map>

class WordConversion
{
public:
	using transType = std::unordered_map<std::string, std::vector<std::string>>;
	WordConversion() = default;
	WordConversion(std::istream &transInfoInput, std::ostream &errOutput, std::istream &userInput, unsigned seed = time(nullptr)) : engine(seed)
	{
		size_t lineNum = 1;
		for(std::string key, val; transInfoInput >> key; ++lineNum)
		{
			std::getline(transInfoInput, val);
			if(val.find_first_not_of(" ") == std::string::npos)
				throw std::runtime_error(std::string("error: 第") + std::to_string(lineNum) + "行键值对格式错误!");
			std::istringstream words(val);
			std::vector<std::string> temp;
			std::copy(std::istream_iterator<std::string>(words), std::istream_iterator<std::string>(), std::back_inserter(temp));
			auto ret = transMap.find(key);
			if(ret != transMap.cend())
			{
				printWaring(errOutput, ret->first, ret->second, temp);
				char c = getInput(userInput, errOutput);
				if(c == 'y')
					ret->second = std::move(temp);
			}
			else
				transMap.emplace(std::move(key), std::move(temp));
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
		if(valueIter == transMap.cend())
			return word;
		std::uniform_int_distribution<unsigned> u(0, valueIter->second.size() - 1);
		return valueIter->second[u(engine)];
	}
	void printWaring(std::ostream &errOutput, const std::string &key, const std::vector<std::string> &oldVal, const std::vector<std::string> &newVal)
	{
		errOutput << "检测到有关键字相同的短语。\n关键字:" << key << "\n原短语:";
		printWord(errOutput, oldVal);
		errOutput << "\n新短语:";
		printWord(errOutput, newVal);
		errOutput << "\n是否替换? y/n ";
	}
	void printWord(std::ostream &os, const std::vector<std::string> &vec)
	{
		for(std::size_t i = 0, size = vec.size(); i < size; ++i)
		{
			os << vec[i];
			if(i != size - 1) os << '|';
		}
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
	std::default_random_engine engine;
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
