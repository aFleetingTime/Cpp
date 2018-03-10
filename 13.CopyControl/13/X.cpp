#include <iostream>
#include <string>

class X
{
public:
	X(const std::string &s) : name(s) { std::cout << "X() 构造函数 " << name << std::endl; }
	X(const X &x)
	{
		(name = x.name).push_back('c'); 
		std::cout << "X(const X &) 拷贝构造函数 " << name << std::endl; 
	}
	~X() { std::cout << "~X() 析构函数 " << name << std::endl; }
	X& operator=(const X &x) 
	{
		(name = x.name).push_back('=');
		std::cout << "operator= 拷贝赋值运算符 " << name << std::endl; return *this;
	};
	std::string name;
};

X test(X &x1, X x2 /* 3.X(X) 1c */, X *x3)
{
	X a("3") /* 4.X() 3 */, b(a) /* 5.X(X) 3c */;
	a = b; /* 6.=() 3c= */
	X *p = new X("4"); /* 7.X() 4 */
	delete x3, delete p; // 8.~X() 2  9.~() 4
	return a; //move a
} // 10.~X() 3c  11.~X() 1c

int main()
{
	X x("1"); // 1.X() 1
	X a = test(x, x, new X("2") /* 2.X() 2 */); // move a(name 3c=) -> a
	std::cout << "------------" << std::endl;
} // 12.~X() 3c=  13.~X() 1
