#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> up1(new int());
	std::unique_ptr<int> up2 = up1;
}
