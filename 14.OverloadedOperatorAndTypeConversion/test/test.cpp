#include <iostream>
#include <string>

int main()
{
#if 0
	std::string s;
	std::size_t ul;
	float f;
	std::cin >> s >> ul >> f;
	std::cout << s << ' ' << ul << ' ' << f << std::endl;
#endif
	delete new const int(1);
}
