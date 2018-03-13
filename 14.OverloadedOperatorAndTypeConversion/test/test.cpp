#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <iterator>

int main()
{
#if 0
	std::string s;
	std::size_t ul;
	float f;
	std::cin >> s >> ul >> f;
	std::cout << s << ' ' << ul << ' ' << f << std::endl;
#endif
#if 0
	delete new const int(1);
#endif
	srand(time(nullptr));
	std::vector<std::string*> pvec;
	for(int i = 0; i < 100; ++i)
		pvec.push_back((std::string*)(rand() % 0xFFFFFFFFF));
	std::copy(pvec.cbegin(), pvec.cend(), std::ostream_iterator<std::string*>(std::cout, "\n"));
	std::sort(pvec.begin(), pvec.end(), [](std::string *p1, std::string *p2) {
		return p1 < p2;
	});
	std::cout << '\n';
	std::copy(pvec.cbegin(), pvec.cend(), std::ostream_iterator<std::string*>(std::cout, "\n"));
}
