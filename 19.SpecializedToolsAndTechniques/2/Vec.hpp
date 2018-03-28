#pragma once
#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

inline void* operator new(std::size_t size)
{
	std::cout << "new " << size << std::endl;
	if(void *mem = malloc(size))
		return mem;
	throw std::bad_alloc();
}
inline void* operator new(std::size_t size, std::nothrow_t) noexcept { std::cout << "new2" << std::endl; return malloc(size); }
inline void operator delete(void *mem) noexcept { 
	std::cout << "delete" << std::endl;
	free(mem); }
inline void operator delete(void *mem, std::nothrow_t) noexcept { free(mem); }

template <typename T>
class Vec
{
public:
	using size_type = std::size_t;
	using value_type = T;

	Vec() noexcept : firstPoint(nullptr), lastPoint(nullptr), curPoint(nullptr) { }
	Vec(std::initializer_list<value_type>);
	Vec(size_type, const value_type &val);
	Vec(const Vec &);
	Vec(Vec &&);
	~Vec();
	Vec& operator=(Vec &&);
	Vec& operator=(const Vec &);
	std::string& operator[](size_type);
	const std::string& operator[](size_type) const;

	template <typename... Args> void emplace_back(Args&&... rest) {
		checkMemory();
		alloc.construct(curPoint++, std::forward<Args>(rest)...);
	}
	void push_back(const value_type &);
	value_type* begin() const noexcept { return firstPoint; }
	value_type* end() const noexcept { return curPoint; }
	size_type size() const noexcept { return curPoint - firstPoint; }
	size_type capacity() const noexcept { return lastPoint - firstPoint; }

private:
	value_type *firstPoint;
	value_type *curPoint;
	value_type *lastPoint;
	static std::allocator<value_type> alloc;

	void checkMemory();
	void freeAlloc();
	void reallocate();
	void moveMemory(Vec &);
	std::pair<value_type*, value_type*> allocFillMemory(size_type, const value_type &);
	std::pair<value_type*, value_type*> allocCopyMemory(const value_type *, const size_type);
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::Vec(std::initializer_list<value_type> list) : Vec()
{
	auto flp = allocCopyMemory(list.begin(), list.size()); 
	firstPoint = flp.first;
	lastPoint = curPoint = flp.second;
}

template <typename T>
Vec<T>::Vec(size_type size, const value_type &val)
{
	auto flp = allocFillMemory(size, val);
	firstPoint = flp.first;
	lastPoint = curPoint = flp.second;
}

template <typename T>
Vec<T>::Vec(const Vec &vec)
{
	auto flp = allocCopyMemory(vec.begin(), vec.size());
	firstPoint = flp.first;
	lastPoint = curPoint = flp.second;
}

template <typename T>
Vec<T>::~Vec()
{
	freeAlloc();
}

template <typename T>
Vec<T>::Vec(Vec &&vec) : firstPoint(vec.firstPoint), lastPoint(vec.lastPoint), curPoint(vec.curPoint)
{
	vec.firstPoint = vec.lastPoint = vec.curPoint = nullptr;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &vec)
{
	auto flp = allocCopyMemory(vec.begin(), vec.size());
	freeAlloc();
	firstPoint = flp.first;
	lastPoint = curPoint = flp.second;
	return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec &&vec)
{
	if(this != &vec)
	{
		freeAlloc();
		moveMemory(vec);
	}
	return *this;
}

template <typename T>
std::string& Vec<T>::operator[](size_type index)
{
	if(index >= size())
		throw std::out_of_range("试图访问非法内存!");
	return firstPoint[index];
}

template <typename T>
const std::string& Vec<T>::operator[](size_type index) const
{
	if(index >= size())
		throw std::out_of_range("试图访问非法内存!");
	return firstPoint[index];
}

template <typename T>
void Vec<T>::moveMemory(Vec &vec)
{
	firstPoint = vec.firstPoint;
	lastPoint = vec.lastPoint;
	curPoint = vec.curPoint;
	vec.firstPoint = vec.lastPoint = curPoint = nullptr;
}

template <typename T>
void Vec<T>::push_back(const value_type &val)
{
	checkMemory();
	alloc.construct(curPoint++, val);
}

template <typename T>
inline std::pair<T*, T*> Vec<T>::allocCopyMemory(const value_type *b, size_type size)
{
	auto temp = alloc.allocate(size);
	return { temp, uninitialized_copy_n(b, size, temp) };
}

template <typename T>
inline void Vec<T>::checkMemory()
{
	if(size() == capacity())
		reallocate();
}

template <typename T>
inline void Vec<T>::freeAlloc()
{
	if(!firstPoint)
		return;
	while(curPoint != firstPoint)
		alloc.destroy(--curPoint);
	alloc.deallocate(firstPoint, capacity()); 
	firstPoint = curPoint = lastPoint = nullptr;
}

template <typename T>
inline void Vec<T>::reallocate()
{
	size_type newCapacity = (capacity() + 1) * 2, oldSize = size() + 1;
	value_type *data = alloc.allocate(newCapacity), *cur = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), data);
	freeAlloc();
	firstPoint = data, curPoint = cur, lastPoint = data + newCapacity;
}

template <typename T>
inline std::pair<T*, T*> Vec<T>::allocFillMemory(size_type size, const value_type &fillVal)
{
	value_type *data = alloc.allocate(size);
	return { data, std::uninitialized_fill_n(data, size, fillVal) };
}
