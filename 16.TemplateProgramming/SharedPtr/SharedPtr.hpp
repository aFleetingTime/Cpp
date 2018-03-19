#pragma once
#include <algorithm>
#include <iostream>
#include "Delete.hpp"

template <typename T> class SharedPtr;
template <typename T> void swap(SharedPtr<T> &, SharedPtr<T> &);

template <typename T>
class SharedPtr final
{
	friend void swap<T>(SharedPtr<T> &, SharedPtr<T> &);

public:
	//构造与析构函数
	SharedPtr() = default;

	~SharedPtr() 
	{
		if(!--*useCount)
		{
			freePtr();
			delete useCount;
		}
		delete del;
		ptr = nullptr;
		del = nullptr;
	}

	template <typename P>
	SharedPtr(P *p) : ptr(p) { }

	template <typename P, typename D>
	SharedPtr(P *p, D d) : ptr(p), del(new Delete<P, D>(d)) { }

	//拷贝移动构造函数
	template <typename P>
	SharedPtr(const SharedPtr<P> &sp) noexcept : ptr(sp.ptr), useCount(&(++*sp.useCount)), del(sp.del ? new decltype(*sp.del)(*sp.del) : nullptr) { }

	template <typename P>
	SharedPtr(SharedPtr<P> &&sp) noexcept : ptr(sp.ptr), useCount(sp.useCount), del(sp.del) 
	{
		sp.ptr = nullptr;
		sp.del = nullptr;
		sp.useCount = new unsigned(1);
	}
	
	SharedPtr(const SharedPtr &sp) noexcept : ptr(sp.ptr), useCount(&(++*sp.useCount)) { if(sp.del) del = *sp.del; }

	void swap(SharedPtr &lhs, SharedPtr &rhs) { swap(lhs, rhs); }

	//拷贝移动赋值运算符
	template <typename P>
	SharedPtr& operator=(SharedPtr<P> sp) noexcept { swap(*this, sp); }

	explicit operator bool() const noexcept { return ptr; }

	template <typename P>
	void reset(P *p)
	{
		if(p == ptr)
			return;
		if(!--*useCount)
		{
			freePtr();
			delete useCount;
		}
		ptr = p;
		useCount = new unsigned(1);
	}

	template <typename P, typename D>
	void reset(P *p, D d)
	{
		if(p == ptr)
			return;
		if(!--*useCount)
		{
			freePtr();
			delete useCount;
		}
		delete del;
		del = new Delete<P, D>(d);
		ptr = p;
		useCount = new unsigned(1);
	}

	//成员访问运算符
	T& operator*() { return *ptr; }
	const T& operator*() const { return *ptr; }

	T* operator->() { return &**this; }
	const T* operator->() const { return &**this; }

	unsigned use_count() { return *useCount; }
	bool unique() { return *useCount; }

private:
	T *ptr = nullptr;
	DeleteBase<T> *del = nullptr;
	unsigned *useCount = new unsigned(1);
	void freePtr() { del ? (*del)(ptr) : delete ptr; }
};

template <typename T> 
void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs)
{
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.del, rhs.del);
	swap(lhs.useCount, rhs.useCount);
}
