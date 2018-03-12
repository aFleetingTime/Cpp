#include <iostream>
#include "Message.h"

int main()
{
	Folder f, f2;
	Message m1("hello,"), m2(" world"), m3("!!!");	
	f.save(m1);
	f.save(m2);
	f.save(m3);
	f.readMessage(std::cout);
	f.remove(m3);
	f.readMessage(std::cout);
	std::cout << "-------" << std::endl;
	f2 = f;
	f2.readMessage(std::cout);
	std::cout << "-------" << std::endl;
	f.save(m3);
	m3.save(f2);
	f.readMessage(std::cout);
	std::cout << "-------" << std::endl;
	f2.readMessage(std::cout);
	std::cout << "----move----" << std::endl;
	f2.readMessage(std::cout);
	m1 = std::move(m2);
	f2.readMessage(std::cout);
}
