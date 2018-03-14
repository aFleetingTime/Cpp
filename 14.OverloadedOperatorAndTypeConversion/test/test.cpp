#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <iterator>

struct Test
{
	Test(int i = 0) : num(i) {}
	operator int&() { return num; }
	operator std::string() const { return std::string(); }
	Test& operator=(int i) { num = i + 1; return *this; }
	int num;
};

struct A
{
	A(int a) {}
	A(double a) {}
};
struct B
{
	B(Test b) {}
};

void manip(const A& a) {}
void manip(const B& b) {}

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
#if 0
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
#endif
#if 0
	Test t, t2(10);
	std::cout << (t = t2) << std::endl;
#endif
	manip(10);
	Test t;
	((std::string)t).size();
	(double)t;
}
