#pragma once
#include "DiscQuote.h"

class BulkQuote : public DiscQuote
{
public:
	using DiscQuote::DiscQuote;
	virtual std::ostream& debug(std::ostream &out) const override {
		Quote::debug(out) << " # discount:" << discount << " # quantity:" << quantity;
		return out;
	}
	virtual double netPrice(std::size_t sales) const override { 
		return (sales >= quantity) ? salesPrice * (1 - discount) * sales : DiscQuote::Quote::netPrice(sales); 
	}
};
