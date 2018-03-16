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
	virtual double netPrice() const override { 
		return (sold >= quantity) ? salesPrice * discount * sold : DiscQuote::Quote::netPrice();
	}
	virtual operator Quote*() const & override { return new BulkQuote(*this); }
	virtual operator Quote*() && override { return new BulkQuote(std::move(*this)); }
};
