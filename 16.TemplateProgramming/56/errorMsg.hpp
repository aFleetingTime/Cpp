#pragma once
#include "debugRep.hpp"
#include "print.hpp"

template <typename... Args>
std::ostream& errorMsg(std::ostream &os, const Args&... rest)
{
	return print(os, debugRep(rest)...);
}
