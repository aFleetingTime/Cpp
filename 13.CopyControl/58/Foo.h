#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Foo
{
public:
	Foo sorted() &&;
	Foo sorted() const &;

private:
	std::vector<int> data;
	mutable std::size_t count = 0;
	void sortData();
};
