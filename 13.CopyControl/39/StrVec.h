#pragma once
#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

class StrVec
{
	friend void swap(StrVec &, StrVec &);

public:
	using size_type = std::size_t;
	using value_type = std::string;

	StrVec() : firstPoint(nullptr), lastPoint(nullptr), curPoint(nullptr) {}
	StrVec(std::initializer_list<value_type>);
	StrVec(size_type, const value_type &val);
	StrVec(const StrVec &);
	StrVec(StrVec &&) noexcept;
	~StrVec();
	StrVec& operator=(StrVec &&) noexcept;
	StrVec& operator=(const StrVec &);

	void push_back(const value_type &);
	value_type* begin() const { return firstPoint; }
	value_type* end() const { return curPoint; }
	size_type size() const { return curPoint - firstPoint; }
	size_type capacity() const { return lastPoint - firstPoint; }

private:
	value_type *firstPoint;
	value_type *curPoint;
	value_type *lastPoint;
	static std::allocator<value_type> alloc;

	void checkMemory();
	void freeAlloc();
	void reallocate();
	void moveMemory(StrVec &);
	std::pair<value_type*, value_type*> allocFillMemory(size_type, const value_type &);
	std::pair<value_type*, value_type*> allocCopyMemory(const value_type *, const size_type);
};
