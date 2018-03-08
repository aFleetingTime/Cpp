#include <iostream>
#include "StrBlob.h"

int main()
{
	StrBlob blob { "first", "last" };
	std::cout << "front: " << blob.front() << "\nback: " << blob.back() << std::endl;
}
