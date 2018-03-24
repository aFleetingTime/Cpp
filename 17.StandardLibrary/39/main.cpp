#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream io("./text", std::ios::out | std::ios::in);
	if(!io)
	{
		std::cerr << "text文件不存在!" << std::endl;
		return EXIT_FAILURE;
	}
	io.seekg(0, std::ios::end);
	auto endMark = io.tellp();
	io.seekg(0, std::ios::beg);
	std::string line;
	while(io.tellg() != endMark && std::getline(io, line))
	{
		auto mark = io.tellg();
		io.seekp(0, std::ios::end);
		io << mark;
		if(mark != endMark) io.put(' ');
		io.seekg(mark);
	}
	io.seekp(0, std::ios::end);
	io.put('\n');
}
