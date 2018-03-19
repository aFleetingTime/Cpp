#pragma once
#include "DeleteBase.hpp"

template <typename T> class SharedPtr;

template <typename T, typename F>
class Delete final : public DeleteBase<T>
{
	friend class SharedPtr<T>;

public:
	virtual ~Delete() = default;

private:
	Delete(F f) : deleteFunc(f) { }
	virtual void operator()(T *p) { deleteFunc(p); }
	F deleteFunc;
	virtual operator DeleteBase<T>*() const &
	{
		return new Delete(*this);
	}
	virtual operator DeleteBase<T>*() &&
	{
		return new Delete(*this);
	}
};
