#pragma once
#include "SharedPtr.hpp"

template <typename T, typename... Args>
SharedPtr<T> makeShared(Args&&... args)
{
	return new T(std::forward<Args>(args)...);
}
