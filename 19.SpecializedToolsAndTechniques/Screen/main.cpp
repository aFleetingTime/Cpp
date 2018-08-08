#include "Screen.h"
#include <chrono>
#include <thread>

int main()
{
#if 0
	Screen s(120, 40);
	s.setColor(std::cout, Screen::Color::BLUE);
	while(s)
	{
		std::cout << "\033[2J" << s.set('@');
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
#endif
	std::cout << "Hello World!\n";
	//std::cout << "\033[6D";
	std::cout << "\033[1A\033[10C";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "ABCDEFG" << std::endl;
}
