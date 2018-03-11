#include "StrBlob.h"

StrBlob::StrBlob() : dataVec(std::make_shared<con_type>()) {}
StrBlob::StrBlob(std::initializer_list<value_type> initList) : dataVec(std::make_shared<con_type>(initList)) {}

StrBlob::StrBlob(const StrBlob &blob) : dataVec(std::make_shared<con_type>(*blob.dataVec)) {} 
StrBlob& StrBlob::operator=(const StrBlob &blob)
{
	dataVec.reset(new con_type(*blob.dataVec));
}

void StrBlob::push_back(const value_type &val)
{
	dataVec->push_back(val);
}
void StrBlob::pop_back()
{
	check(0, "没有可删除的元素!");
	dataVec->pop_back();
}

std::string& StrBlob::back()
{
	check(0, "容器中元素为空!");
	return dataVec->back();
}
std::string& StrBlob::front()
{
	check(0, "容器中元素为空!");
	return dataVec->front();
}
const std::string& StrBlob::back() const
{
	check(0, "容器中元素为空!");
	return dataVec->back();
}
const std::string& StrBlob::front() const
{
	check(0, "容器中元素为空!");
	return dataVec->front();
}
StrBlob::size_type StrBlob::size()
{
	return dataVec->size();
}
StrBlob::size_type StrBlob::size() const
{
	return dataVec->size();
}
void StrBlob::check(size_type index, const std::string &errorInfo) const
{
	if(index >= dataVec->size())
		throw std::out_of_range(errorInfo);
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this, 0); }
const StrBlobPtr StrBlob::begin() const { return StrBlobPtr(*this, 0); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, size()); }
const StrBlobPtr StrBlob::end() const { return StrBlobPtr(*this, size()); }


StrBlobPtr::StrBlobPtr() : index(0) {}
StrBlobPtr::StrBlobPtr(StrBlob &sb, size_t i) : wptr(sb.dataVec), index(i) {}
StrBlobPtr::StrBlobPtr(const StrBlob &sb, size_t i) : wptr(sb.dataVec), index(i) {}

const std::string& StrBlobPtr::operator*() const
{
	return (*check(index, "数组越界"))[index];
}
std::string& StrBlobPtr::operator*()
{
	return (*check(index, "数组越界"))[index];
}

StrBlobPtr& StrBlobPtr::operator++()
{
	check(index, "++");
	++index;
	return *this;
}
const StrBlobPtr& StrBlobPtr::operator++() const
{
	check(index, "++");
	++index;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	--index;
	check(index, "--");
	return *this;
}
const StrBlobPtr& StrBlobPtr::operator--() const
{
	--index;
	check(index, "--");
	return *this;
}

StrBlobPtr::ret_type StrBlobPtr::check(size_t i, std::string errorInfo) const
{
	auto ptr = wptr.lock();
	if(!ptr)
		throw std::runtime_error("访问被拒绝，对象已被销毁");
	if(i >= ptr->size())
		throw std::out_of_range("访问越界");
	return ptr;
}

bool StrBlobPtr::operator!=(const StrBlobPtr &p) const
{
	return wptr.lock() == p.wptr.lock() && index != p.index;
}
