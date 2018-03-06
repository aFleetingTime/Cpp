#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

int main(int args, char *argv[])
{
	if(args != 4)
	{
		std::cerr << "./name <src odd even>" << std::endl;
		return -1;
	}

	std::ifstream srcfile(argv[1]);
	std::ofstream oddfile(argv[2], std::ofstream::app), evenfile(argv[3], std::ofstream::app);

	if(!srcfile || !oddfile || !evenfile)
	{
		std::cerr << "open file error" << std::endl;
		return -2;
	}

	std::istream_iterator<int> src(srcfile), eof;
	std::ostream_iterator<int> odd(oddfile, " "), even(evenfile, "\n");

	std::for_each(src, eof, 
			[&](const int &num)
			{ *(num % 2 ? odd : even)++ = num; });
	//while(src != eof) ((*src % 2) ? *odd++ : *even++) = *src++;
}
