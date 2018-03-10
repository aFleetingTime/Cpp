#include <iostream>

class A
{
public:
	A() = default;
private:
	~A();
};

class B
{
public:
	//B() {}
	void operator=(const B &b) const {}
	void test() = delete;
	~B() {}
	B(const B &b) {}
	B() = default;
};

int main()
{
	B b;
	//const B b, c = b;
	A *a = new A;
	//delete a; //error: A的析构函数是删除的
}
