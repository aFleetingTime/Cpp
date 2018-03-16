#pragma once
#include <string>
#include <iostream>

class Quote
{
public:
	Quote() : bookNo(""), salesPrice(0.0) { }
	Quote(const std::string &isbn, double price) : bookNo(isbn), salesPrice(price) { }
	Quote(const Quote &rhs) : bookNo(rhs.bookNo), salesPrice(rhs.salesPrice), sold(rhs.sold) { }
	Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), salesPrice(rhs.salesPrice), sold(rhs.sold) {
		rhs.salesPrice = 0.0;
		rhs.sold = 0;
	}
	virtual ~Quote() = default;
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
	virtual double netPrice() const { return sold * salesPrice; }
	std::string isbn() const { return bookNo; }
	void addSold(std::size_t n) { sold += n; }
	void addSold(const Quote &rhs) { sold += rhs.sold; }
	static double printTotal(std::ostream &os, const Quote &item)
	{
		double price = item.netPrice();
		std::cout << "ISBN: " << item.bookNo << " # sold: " << item.sold << " | price: " << item.salesPrice << " | total: " << price << std::endl;
		return price;
	}
	virtual operator Quote*() const & { return new Quote(*this); }
	virtual operator Quote*() && { return new Quote(std::move(*this)); }

private:
	std::string bookNo;

protected:
	double salesPrice;
	std::size_t sold = 0;
};
