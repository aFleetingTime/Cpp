#include "StrBlob.h"

StrBlob::StrBlob() : dataVec(std::make_shared<con_type>()) {}
StrBlob::StrBlob(std::initializer_list<value_type> initList) : dataVec(std::make_shared<con_type>(initList)) {}

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
void StrBlob::check(size_type index, const std::string &errorInfo) const
{
	if(index >= dataVec->size())
		throw std::out_of_range(errorInfo);
}
