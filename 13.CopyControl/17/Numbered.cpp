#include <iostream>

class Numbered
{
	friend void func1(Numbered num);
	friend void func2(const Numbered &num);
public:
	Numbered() : mysn(num++) {}
#ifdef COPY
	Numbered(const Numbered &n) : mysn(num++) {}
	Numbered& operator=(const Numbered &n) { mysn = num++; }
#endif
private:
	size_t mysn;
	static size_t num;
};
size_t Numbered::num = 0;

void func1(Numbered num) { std::cout << num.mysn << std::endl; }
void func2(const Numbered &num) { std::cout << num.mysn << std::endl; }

int main()
{
	Numbered a, b = a, c = b;
	func1(a); func1(b); func1(c);
#ifdef COPY
	func2(a); func2(b); func2(c);
#endif
}
