#include <iostream>
#include <iterator>
#include "StrBlob.h"

int main()
{
	StrBlob blob;
	for(std::string line; std::getline(std::cin, line); blob.push_back(std::move(line)));
	int i = 0;
	for(const auto beg = blob.begin(); beg + i != blob.end(); beg + i++)
		std::cout << *(beg + i) << std::endl;
}
