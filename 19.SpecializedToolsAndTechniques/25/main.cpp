#include <iostream>
#include "Token.h"

int main()
{
	Token t;
	t = 3.14;
	std::cout << *to_pointer<double>(t.getValue()) << std::endl;
	t = 10;
	std::cout << *to_pointer<int>(t.getValue()) << std::endl;
	t = 'a';
	std::cout << *to_pointer<char>(t.getValue()) << std::endl;
	Token k = t;
	t = "test";
	std::cout << *to_pointer<char>(k.getValue()) << std::endl;
	std::cout << *to_pointer<std::string>(t.getValue()) << std::endl;
	k = t;
	std::cout << *to_pointer<std::string>(k.getValue()) << std::endl;
	t = t;
	std::cout << *to_pointer<std::string>(t.getValue()) << std::endl;
}
