#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>

int main()
{
	try {
		std::vector<int> vec(-1);
	} catch(std::exception &exc) {
		std::cout << exc.what() << std::endl;
		abort();
	}
}
