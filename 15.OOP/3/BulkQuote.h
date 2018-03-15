#pragma once
#include "Quote.h"

class BulkQuote : public Quote
{
public:
	BulkQuote() = default;
	BulkQuote(const std::string &isbn, double price, float dis, std::size_t qty) : Quote(isbn, price), discount(1 - dis), minQty(qty) { }
	virtual ~BulkQuote() override = default;
	virtual std::ostream& debug(std::ostream &out) const override
	{
		Quote::debug(out) << " # discount:" << discount << " # minQty:" << minQty;
		return out;
	}
	virtual double netPrice(std::size_t sales) const override { return (sales >= minQty) ? salesPrice * (1 - discount) * sales : Quote::netPrice(sales); }

protected:
	float discount = 0;
	std::size_t minQty = 0.0;
};
