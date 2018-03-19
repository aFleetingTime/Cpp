#pragma once

template <typename T, typename F>
F for_each(const T &vals, F func)
{
	for(typename T::size_type pos = 0, size = vals.size(); pos < size; ++pos)
		func(vals.at(pos));
	return func;
}
