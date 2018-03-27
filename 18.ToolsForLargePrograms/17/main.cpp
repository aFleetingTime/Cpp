#include <iostream>
#include <iomanip>

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
#ifdef A
//using Exercise::ivar;		//编译不通过，ivar已在该作用域声明。
using Exercise::dvar;
using Exercise::limit;
#endif
#ifdef C
using namespace Exercise;	//对ivar具有二义性
#endif
void manip()
{
#ifdef B
	using Exercise::ivar;
	//using Exercise::dvar;	//编译不通过，manip的局部变量dvar重定义。
	using Exercise::limit;
#endif
#ifdef D
	using namespace Exercise;//同C
#endif
	double dvar = 3.1416;	//AC都会隐藏命名空间Exercise的成员dvar。
	int iobj = limit + 1;	//Exercise的limit
	++ivar;					//BCD都递增Exercise的ivar。
	++::ivar;				//ABCD都递增全局作用域的ivar。
}

int main()
{
	manip();
	using namespace Exercise;
	std::cout << std::setw(7) << "ivar: " << std::setw(8) << Exercise::ivar << std::endl
			  << std::setw(7) << "givar: " << std::setw(8) << ::ivar << std::endl
			  << std::setw(7) << "dvar: " << std::setw(8) << dvar << std::endl
			  << std::setw(7) << "limit: " << std::setw(8) << limit << std::endl;
}
