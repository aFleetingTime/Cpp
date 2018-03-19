#include <unistd.h>
#include <fstream>
#include "TextQuery.h"
#include "QueryResult.h"

template class std::vector<std::string>;

std::string getPath(const std::string opInfo)
{
	std::string path;
	do
	{
		while(std::cout << opInfo && !(std::cin >> path))
		{
			std::cerr << "\n输入无效, 请重新输入文件路径...\n";
			std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.eofbit);
		}
	} while(access(path.c_str(), F_OK) && std::cerr << "指定文件不存在, 请重新输入...\n");
	return path;
}

void runQueries(std::ifstream &text)
{
	TextQuery query(text);
	std::string input;
	while(std::cout << "待查询字符: " && std::cin >> input && input != "q")
	{
		if(input == "r")
		{
			text.close();
			std::cout << '\n';
			text.open(getPath("重新指定目标文件路径: "));
			query.retext(text);
		}
		else
			std::cout << '\n' << query.query(input);
		std::cout << std::endl;
	}
}

int main()
{
	std::ifstream textFile(getPath("目标文件路径: "));
	std::cout << std::endl;
	std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.eofbit);
	runQueries(textFile);
}
