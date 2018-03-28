#include "Screen.h"
#include <unistd.h>

int main()
{
	Screen s(120, 40);
	std::cout << "\033[?25l";
	while(s)
	{
		std::cout << "\033[2J"  << s.set('@');
		usleep(75000);
	}
	std::cout << "\033[?25h";
}
