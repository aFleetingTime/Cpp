#pragma once
#include <iostream>

template <typename T, typename F>
F for_each(T beg, const T end, F func)
{
	while(beg != end)
		func(*beg++);
	return func;
}
