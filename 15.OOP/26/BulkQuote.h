#pragma once
#include "DiscQuote.h"

class BulkQuote : public DiscQuote
{
public:
	BulkQuote() {
		std::cout << "BulkQuote()" << std::endl;
	}
	BulkQuote(const std::string &isbn, double price, float disc, std::size_t qty) : DiscQuote(isbn, price, disc, qty) {
		std::cout << "BulkQuote(isbn, price, disc, qty)" << std::endl;
	}
	BulkQuote(const BulkQuote &rhs) : DiscQuote(rhs) {
		std::cout << "BulkQuote(Quote&)" << std::endl;
	}
	BulkQuote(BulkQuote &&rhs) noexcept : DiscQuote(std::move(rhs)) {
		std::cout << "BulkQuote(Quote&&)" << std::endl;
	}
	virtual ~BulkQuote() override {
		std::cout << "~BulkQuote()" << std::endl;
	}
	BulkQuote& operator=(const BulkQuote &rhs) {
		DiscQuote::operator=(rhs);
		std::cout << "operator=(BulkQuote&)" << std::endl;
	}
	BulkQuote& operator=(BulkQuote &&rhs) noexcept {
		DiscQuote::operator=(std::move(rhs));
		std::cout << "operator=(BulkQuote&&)" << std::endl;
	}
	virtual std::ostream& debug(std::ostream &out) const override {
		Quote::debug(out) << " # discount:" << discount << " # quantity:" << quantity;
		return out;
	}
	virtual double netPrice(std::size_t sales) const override { 
		return (sales >= quantity) ? salesPrice * (1 - discount) * sales : DiscQuote::Quote::netPrice(sales); 
	}
};
