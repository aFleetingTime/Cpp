#include "Screen.h"

int main()
{
	Screen<5, 10> s;
	std::cout << s << std::endl;
	s.set('i');
	std::cout << s << std::endl;
}
