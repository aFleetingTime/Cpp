#include <iostream>
#include <exception>

struct exception
{
	exception() { std::cout << "e()" << std::endl; }
	~exception() { std::cout << "~e()" << std::endl; }
	exception(const exception &e) { std::cout << "e(c e&)" << std::endl; }
	exception(exception &&e) { std::cout << "e(e&&)" << std::endl; }
	exception& operator=(const exception &e) { std::cout << "=e(c e&)" << std::endl; }
	exception& operator=(exception &&e) { std::cout << "=e(e&&)" << std::endl; }
};
struct Test
{
	~Test() { throw std::exception(); }
};

void fun()
{
	throw exception();
}

int main()
{
#if 0
	try
	{
		try
		{
			try
			{
				throw std::exception();
			} catch(int i) {
			}
		} catch(char c) {
		}
	} catch(std::exception exc) {
		std::cout << exc.what() << std::endl;
	}
#endif
	try {
		fun();
	} catch(exception exc) {
		std::cout << "exception" << std::endl;
	} catch(std::out_of_range ofr) {
		std::cout << ofr.what() << std::endl;
	}
}
