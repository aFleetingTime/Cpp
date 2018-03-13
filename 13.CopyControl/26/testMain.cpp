#include <iostream>
#include <iterator>
#include "StrBlob.h"

int main()
{
	StrBlob blob;
	for(std::string line; std::getline(std::cin, line); blob.push_back(std::move(line)));
	blob = blob;
	for(auto &s : blob)
		std::cout << s << std::endl;
}
