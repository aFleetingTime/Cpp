#include <tuple>
#include <bitset>
#include <vector>
#include <iostream>

int main()
{
	std::bitset<32> bits;
	std::cin >> bits;
	std::cout << (bits ^ std::bitset<32>(0xFFFFFFFF)) << std::endl;
	int a[2] { 0, 1 };
	auto [x, y] = a;
	auto v = std::vector { 1,2,3,4,5 };
	std::vector l{ 1,2,3,4,5 };
}
