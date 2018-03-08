#pragma once
#include <vector>
#include <string>
#include <memory>

class StrBlob
{
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

	size_type size();
private:
	std::shared_ptr<std::vector<value_type>> dataVec;
	void check(size_type index, const std::string &errorInfo) const;
};
