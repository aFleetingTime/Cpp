#pragma once
#include "DiscQuote.h"

class BulkQuote : public DiscQuote
{
public:
	BulkQuote() = default;
	BulkQuote(const std::string &isbn, double price, float disc, std::size_t qty) : DiscQuote(isbn, price, disc, qty) { }
	virtual ~BulkQuote() override = default;
	virtual std::ostream& debug(std::ostream &out) const override
	{
		Quote::debug(out) << " # discount:" << discount << " # quantity:" << quantity;
		return out;
	}
	virtual double netPrice(std::size_t sales) const override { return (sales >= quantity) ? salesPrice * (1 - discount) * sales : DiscQuote::Quote::netPrice(sales); }
};
