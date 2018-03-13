#include "StrVec.h"

std::allocator<StrVec::value_type> StrVec::alloc;

StrVec::StrVec(std::initializer_list<value_type> list) : StrVec()
{
	auto flp = allocCopyMemory(list.begin(), list.size()); 
	firstPoint = flp.first;
	lastPoint = curPoint = flp.second;
}

StrVec::StrVec(size_type size, const value_type &val)
{
	auto flp = allocFillMemory(size, val);
	firstPoint = flp.first;
	lastPoint = curPoint = flp.second;
}

StrVec::StrVec(const StrVec &svec)
{
	auto flp = allocCopyMemory(svec.begin(), svec.size());
	firstPoint = flp.first;
	lastPoint = curPoint = flp.second;
}

StrVec::~StrVec()
{
	freeAlloc();
}

StrVec::StrVec(StrVec &&svec) noexcept : firstPoint(svec.firstPoint), lastPoint(svec.lastPoint), curPoint(svec.curPoint)
{
	svec.firstPoint = svec.lastPoint = svec.curPoint = nullptr;
}

StrVec& StrVec::operator=(const StrVec &svec)
{
	auto flp = allocCopyMemory(svec.begin(), svec.size());
	freeAlloc();
	firstPoint = flp.first;
	lastPoint = curPoint = flp.second;
	return *this;
}

StrVec& StrVec::operator=(StrVec &&svec) noexcept
{
	if(this != &svec)
	{
		freeAlloc();
		moveMemory(svec);
	}
	return *this;
}

std::string& StrVec::operator[](size_type index)
{
	if(index >= size())
		throw std::out_of_range("试图访问非法内存!");
	return firstPoint[index];
}

const std::string& StrVec::operator[](size_type index) const
{
	if(index >= size())
		throw std::out_of_range("试图访问非法内存!");
	return firstPoint[index];
}

void StrVec::moveMemory(StrVec &svec)
{
	firstPoint = svec.firstPoint;
	lastPoint = svec.lastPoint;
	curPoint = svec.curPoint;
	svec.firstPoint = svec.lastPoint = curPoint = nullptr;
}

void StrVec::push_back(const value_type &val)
{
	checkMemory();
	alloc.construct(curPoint++, val);
}

inline std::pair<StrVec::value_type*, StrVec::value_type*> StrVec::allocCopyMemory(const value_type *b, size_type size)
{
	auto temp = alloc.allocate(size);
	return { temp, uninitialized_copy_n(b, size, temp) };
}

inline void StrVec::checkMemory()
{
	if(size() == capacity())
		reallocate();
}

inline void StrVec::freeAlloc()
{
	if(!firstPoint)
		return;
	while(curPoint != firstPoint)
		alloc.destroy(--curPoint);
	alloc.deallocate(firstPoint, capacity()); 
	firstPoint = curPoint = lastPoint = nullptr;
}

inline void StrVec::reallocate()
{
	size_type newCapacity = (capacity() + 1) * 2, oldSize = size() + 1;
	value_type *data = alloc.allocate(newCapacity), *cur = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), data);
	freeAlloc();
	firstPoint = data, curPoint = cur, lastPoint = data + newCapacity;
}

inline std::pair<StrVec::value_type*, StrVec::value_type*> StrVec::allocFillMemory(size_type size, const value_type &fillVal)
{
	value_type *data = alloc.allocate(size);
	return { data, std::uninitialized_fill_n(data, size, fillVal) };
}
