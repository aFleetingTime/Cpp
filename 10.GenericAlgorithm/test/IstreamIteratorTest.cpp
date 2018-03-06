#include <iostream>
#include <iterator>
#include <unistd.h>

int main()
{
	std::istream_iterator<int> input(std::cin);
	sleep(1);
	//input++;
	//int num = *input++;
	//std::cout << "num: " << num << std::endl;
	//std::cout << "num: " << num << std::endl;
}
