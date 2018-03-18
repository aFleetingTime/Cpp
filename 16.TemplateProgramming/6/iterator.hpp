#pragma once

template <typename Type, unsigned Size>
Type* begin(Type (&array)[Size])
{
	return array;
}

template <typename Type, unsigned Size>
Type* end(Type (&array)[Size])
{
	return array + Size;
}
