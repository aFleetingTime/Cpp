#include <new>
#include <iostream>
#include <cstddef>

class Class
{
public:
	static int Class::* data();
private:
	int i = 1;
};
int Class::* Class::data() {
	return &Class::i;
}

int main()
{
	Class c;
	std::cout << c.*Class::data() << std::endl;
}
