#include "BulkQuote.h"

class LimitedQuote : public BulkQuote
{
public:
	using BulkQuote::BulkQuote;
	LimitedQuote() = default;
	virtual ~LimitedQuote() override = default;
	virtual std::ostream& debug(std::ostream &out) const override {
		BulkQuote::debug(out);
	}
	virtual double netPrice() const override {
		if(sold > quantity) return (salesPrice * discount * quantity) + (sold - quantity) * salesPrice;
		return salesPrice * discount * sold;
	}
	virtual operator Quote*() const & override { return new LimitedQuote(*this); }
	virtual operator Quote*() && override { return new LimitedQuote(std::move(*this)); }
};
