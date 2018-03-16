#include <iostream>

// 编译器认为对象的类型在构造或析构的过程中仿佛发生了改变一样，如果构造函数或析构函数调用了某个虚函数，所调用的函数版本始终为构造函数所在的类的版本。

class B
{
public:
	B() { print(); }
	virtual void print() const { std::cout << "B::print() " << this << std::endl; }
};

class D : public B
{
public:
	D() : B() { print(); }
	virtual void print() const override { std::cout << "D::print() " << this << std::endl; }
};

int main()
{
	D d;
}
