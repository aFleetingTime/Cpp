#include "BulkQuote.h"

class LimitedQuote : public BulkQuote
{
public:
	LimitedQuote() = default;
	LimitedQuote(const std::string &isbn, double price, float disc, std::size_t max) : BulkQuote(isbn, price, disc, max) { }
	virtual ~LimitedQuote() override = default;
	virtual std::ostream& debug(std::ostream &out) const override
	{
		BulkQuote::debug(out);
	}
	virtual double netPrice(std::size_t sales) const override
	{
		if(sales > quantity) return (salesPrice * discount * quantity) + (sales - quantity) * salesPrice;
		return salesPrice * discount * sales;
	}
};
