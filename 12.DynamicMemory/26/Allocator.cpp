#include <iostream>
#include <string>
#include <memory>

int main()
{
	std::allocator<std::string> alloc;
	constexpr int maxSize = 20;
	std::string *const beg = alloc.allocate(maxSize), *end = beg;
	for(std::string s; std::cout << "input: " && std::cin >> s; alloc.construct(end++, s));
	std::cout << std::endl;
	for(std::string *p = beg; p != end; ++p)
		std::cout << *p << ' ';
	std::cout << std::endl;
	while(beg != end)
		alloc.destroy(--end);
	alloc.deallocate(beg, maxSize);
}
