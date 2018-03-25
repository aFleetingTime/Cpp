#include <iostream>
#include <string>
#include "ItemExcp.h"

template <typename T> class hash;

class Sales_item
{
	friend std::ostream &operator<<(std::ostream &, const Sales_item &item);
	friend std::istream &operator>>(std::istream &, Sales_item &item);
	friend Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs);
	friend class std::hash<Sales_item>;
	
public:
	Sales_item() noexcept : Sales_item(std::string("")) { }
	Sales_item(std::istream &input) { input >> bookNo >> unitsSold >> revenue; }
	Sales_item(const std::string &bNo, size_t sold = 0, double rev = 0.0) : bookNo(bNo), unitsSold(sold), revenue(rev) {}
	Sales_item &operator+=(const Sales_item &sec) 
	{
		if(this->isbn() != sec.isbn())
			throw isbn_mismatch("isbn mismatch", this->isbn(), sec.isbn());
		unitsSold += sec.unitsSold; 
		revenue += sec.revenue;
		return *this; 
	}

	std::string isbn() const { return bookNo; }

	bool operator==(const Sales_item &sec) const { return bookNo == sec.bookNo && unitsSold == sec.unitsSold && revenue == sec.revenue; }
	bool operator!=(const Sales_item &sec) const { return !(*this == sec); }

	double avgPrice() const { return unitsSold ? revenue / unitsSold : 0; }

private:
	std::string bookNo;
	size_t unitsSold;
	double revenue;
};

namespace std
{
	template <>
	class hash<Sales_item>
	{
	public:
		using result_type = size_t;
		using argument_type = Sales_item;
		result_type operator()(const argument_type &s) const noexcept;
	};
	hash<Sales_item>::result_type hash<Sales_item>::operator()(const argument_type &s) const noexcept {
		return hash<string>()(s.bookNo) ^ hash<size_t>()(s.unitsSold) ^ hash<double>()(s.revenue);
	}
}

Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs)
{
	return Sales_item(lhs) += rhs;
}

inline std::ostream &operator<<(std::ostream &output, const Sales_item &item)
{
	output << item.bookNo << ' ' << item.unitsSold << ' ' << item.revenue << ' ' << item.avgPrice();
	return output;
}

inline std::istream &operator>>(std::istream &input, Sales_item &item)
{
	if(!input)
		return input;
	input >> item.bookNo >> item.unitsSold >> item.revenue;
	return input;
}

inline bool compareIsbn(const Sales_item &s1, const Sales_item &s2)
{
	return s1.isbn() < s2.isbn();
}
