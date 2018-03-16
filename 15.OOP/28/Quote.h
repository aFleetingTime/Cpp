#pragma once
#include <string>

class Quote
{
public:
	Quote() : bookNo(""), salesPrice(0.0) { }
	Quote(const std::string &isbn, double price) : bookNo(isbn), salesPrice(price) { }
	Quote(const Quote &rhs) : bookNo(rhs.bookNo), salesPrice(rhs.salesPrice) { }
	Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), salesPrice(rhs.salesPrice) {
		rhs.salesPrice = 0.0;
	}
	virtual ~Quote() { }
	Quote& operator=(const Quote &rhs) {
		bookNo = rhs.bookNo;
		salesPrice = rhs.salesPrice;
	}
	Quote& operator=(Quote &&rhs) noexcept {
		bookNo = std::move(rhs.bookNo);
		salesPrice = rhs.salesPrice;
		rhs.salesPrice = 0.0;
	}

	virtual std::ostream& debug(std::ostream &out) const {
		out << "bookNo:" << bookNo << " # salesPrice:" << salesPrice; 
		return out;
	}
	virtual double netPrice(std::size_t sales) const { return sales * salesPrice; }
	std::string isbn() const { return bookNo; }

private:
	std::string bookNo;

protected:
	double salesPrice;
};
