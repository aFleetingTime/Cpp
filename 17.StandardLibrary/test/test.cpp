#include <tuple>
#include <bitset>
#include <vector>
#include <iostream>
#include <sstream>
#include <random>
#include <iterator>
#include <algorithm>

std::vector<unsigned> random(std::size_t size)
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u;
	std::vector<unsigned> ret;
	for(std::size_t i = 0; i < size; ++i)
		ret.push_back(u(e));
	return ret;
}

int main()
{
#if 0
	std::bitset<32> bits;
	std::cin >> bits;
	std::cout << (bits ^ std::bitset<32>(0xFFFFFFFF)) << std::endl;
	int a[2] { 0, 1 };
	auto [x, y] = a;
	auto v = std::vector { 1,2,3,4,5 };
	std::vector l{ 1,2,3,4,5 };
#endif
#if 0
	std::ostream_iterator<unsigned> beg(std::cout, "\n");
	std::vector<unsigned> vec1 = random(5);
	std::vector<unsigned> vec2 = random(5);
	std::copy(vec1.cbegin(), vec1.cend(), beg);
	std::copy(vec2.cbegin(), vec2.cend(), beg);
#endif
#if 0
	std::default_random_engine e1(1);
	std::default_random_engine e2(2);
	e2();
	std::cout << e1() << "  " << e2() << std::endl;
#endif
#if 0
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u;
	while(1)
	{
		e.seed(0);
		std::cout << u(e) << std::endl;
	}
#endif
#if 0
	std::cout << std::boolalpha << true << " " << false << std::noboolalpha << std::endl;
	std::cout << true << " " << false << std::endl;
#endif
#if 0
	double d = 3.1415926;
	std::cout << "default: " << std::cout.precision() << " value: " << d << std::endl;
	int old = std::cout.precision(1);
	std::cout << "precision: " << std::cout.precision() << " value: " << d << std::endl;
	std::cout.precision(8);
	std::cout << "precision: " << std::cout.precision() << " value: " << d << std::endl;
	std::cout.precision(old);
	std::cout << "precision: " << std::cout.precision() << std::endl;
#endif
#if 0
	double d = 3.0;
	//std::cout << std::hexfloat << std::uppercase <<  d << std::defaultfloat << std::nouppercase << std::endl;
	std::cout << d << std::endl;
	std::cout << std::fixed << d << std::defaultfloat << std::endl;
	std::cout << d << std::endl;
#endif
#if 0
	std::string s("Hello World!!!");
	std::istringstream iss(s);
	for(int i = 0; i < 5; std::cin.get(), ++i);
	//for(int i = 0; i < 5; std::cin.unget(), ++i);
	char c = 0;
	//while(std::cin.get(c) && c != -1)
	std::string temp;
	while(iss >> temp)
	{
		std::cout << temp;
	std::cout << iss.gcount() << std::endl;
	}
	std::cout << iss.gcount() << std::endl;
#endif
	int c = -1;
	while((c = std::cin.get()) != EOF)
		std::cout.put(c);
}
