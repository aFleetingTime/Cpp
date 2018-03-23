#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

int main()
{
	std::cout << std::hexfloat << std::uppercase << std::setw(20) << sqrt(2.0) << std::endl
			  << std::scientific << std::setw(20) << sqrt(2.0) << std::nouppercase << std::endl
			  << std::fixed << std::setw(20) << sqrt(2.0) << std::endl
			  << std::defaultfloat << std::setw(20) << sqrt(2.0) << std::endl;
}
