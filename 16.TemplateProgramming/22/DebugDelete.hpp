#pragma once
#include <iostream>

class DebugDelete
{
public:
	DebugDelete(std::ostream &);
	template <typename T>
	void operator()(T *) const;

private:
	std::ostream &os;
};

DebugDelete::DebugDelete(std::ostream &out) : os(out) { }

template <typename T>
void DebugDelete::operator()(T *p) const
{
	os << "deleting unique_ptr pointer: " << p << std::endl;
	delete p;
}
