#pragma once
#include <vector>
#include <string>
#include <memory>

class StrBlob;

class StrBlobPtr
{
public:
	using ptr_type = std::weak_ptr<std::vector<std::string>>;

	StrBlobPtr();
	explicit StrBlobPtr(const StrBlob &, size_t);

	std::string& operator*();
	const std::string& operator*() const;

	StrBlobPtr& operator++();
	const StrBlobPtr& operator++() const;

	StrBlobPtr& operator--();
	const StrBlobPtr& operator--() const;

	bool operator!=(const StrBlobPtr &);

private:
	using ret_type = std::shared_ptr<std::vector<std::string>>;
	ret_type check(size_t i, std::string errorInfo) const;

	ptr_type wptr;
	mutable size_t index;
};

class StrBlob
{
	friend StrBlobPtr::StrBlobPtr(const StrBlob &, size_t);

public:
	using value_type = std::string;
	using size_type = std::string::size_type;
	using con_type = std::vector<value_type>;

	StrBlob();
	StrBlob(std::initializer_list<value_type>);

	void push_back(const value_type &);
	void pop_back();

	std::string& back();
	std::string& front();
	const std::string& back() const;
	const std::string& front() const;

	StrBlobPtr begin();
	const StrBlobPtr begin() const;
	StrBlobPtr end();
	const StrBlobPtr end() const;

	size_type size();
	size_type size() const;
private:
	std::shared_ptr<std::vector<value_type>> dataVec;
	void check(size_type index, const std::string &errorInfo) const;
};
