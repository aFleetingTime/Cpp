#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename Type, std::size_t Size>
void print(const Type (&array)[Size])
{
	std::copy(std::cbegin(array), std::cend(array), std::ostream_iterator<Type>(std::cout, "\n"));
}
