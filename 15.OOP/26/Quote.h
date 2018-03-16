#pragma once
#include <string>

class Quote
{
public:
	Quote() : bookNo(""), salesPrice(0.0) {
		std::cout << "Quote()" << std::endl;
	}
	Quote(const std::string &isbn, double price) : bookNo(isbn), salesPrice(price) {
		std::cout << "Quote(isbn, price)" << std::endl;
	}
	Quote(const Quote &rhs) : bookNo(rhs.bookNo), salesPrice(rhs.salesPrice) {
		std::cout << "Quote(Quote&)" << std::endl;
	}
	Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), salesPrice(rhs.salesPrice) {
		rhs.salesPrice = 0.0;
		std::cout << "Quote(Quote&&)" << std::endl;
	}
	virtual ~Quote() {
		std::cout << "~Quote()" << std::endl;
	}
	Quote& operator=(const Quote &rhs) {
		bookNo = rhs.bookNo;
		salesPrice = rhs.salesPrice;
		std::cout << "operator=(Quote&)" << std::endl;
	}
	Quote& operator=(Quote &&rhs) noexcept {
		bookNo = std::move(rhs.bookNo);
		salesPrice = rhs.salesPrice;
		rhs.salesPrice = 0.0;
		std::cout << "operator=(Quote&&)" << std::endl;
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
