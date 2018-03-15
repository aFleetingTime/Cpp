#pragma once
#include <string>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &isbn, double price) : bookNo(isbn), salesPrice(price) { }

	virtual ~Quote() = default;
	virtual std::ostream& debug(std::ostream &out) const
	{
		out << "bookNo:" << bookNo << " # salesPrice:" << salesPrice; 
		return out;
	}
	virtual double netPrice(std::size_t sales) const { return sales * salesPrice; }
	std::string isbn() const { return bookNo; }

private:
	const std::string bookNo = "";

protected:
	double salesPrice = 0.0;
};
