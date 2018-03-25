//#include "Object.h"

namespace Test {
	int i = 0;
}
void func()
{
	using namespace Test;
	i = 2;
}

int main()
{
#if 0
	i = 3;
	n = 4;
	s = 5;
#endif
	//i = 3;
}
