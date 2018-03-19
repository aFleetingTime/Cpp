#pragma once

template <typename T> class SharedPtr;

template <typename T>
class DeleteBase
{
	friend class SharedPtr<T>;

public:
	virtual ~DeleteBase() = default;

private:
	virtual void operator()(T *) = 0;
	virtual operator DeleteBase*() const & = 0;
	virtual operator DeleteBase*() && = 0;
};
