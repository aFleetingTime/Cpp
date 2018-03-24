#include <iostream>
#include <exception>

struct exception
{
	exception() { std::cout << "e()" << std::endl; }
	virtual void fun() const && noexcept final { }
	~exception() { std::cout << "~e()" << std::endl; }
	exception(const exception &e) { std::cout << "e(c e&)" << std::endl; }
	exception(exception &&e) { std::cout << "e(e&&)" << std::endl; }
	exception& operator=(const exception &e) { std::cout << "=e(c e&)" << std::endl; }
	exception& operator=(exception &&e) { std::cout << "=e(e&&)" << std::endl; }
	int a;
};
struct Test
{
	Test() = default;	//合成默认构造函数默认为noexcept
};

void fun() noexcept(false)
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
#if 0
	try {
		void(*p)() noexcept(false) = fun;
		p();
	} catch(exception exc) {
		std::cout << "exception" << std::endl;
	} catch(std::out_of_range ofr) {
		std::cout << ofr.what() << std::endl;
	}
#endif
	void(*p)() noexcept(true) = fun;
	std::cout << std::boolalpha << noexcept(fun()) << std::endl;
	std::cout << noexcept(fun) << std::noboolalpha << std::endl;
	std::cout << noexcept(p()) << std::noboolalpha << std::endl;
	std::cout << noexcept(Test()) << std::noboolalpha << std::endl;
	std::cout << noexcept(exception()) << std::noboolalpha << std::endl;
}
