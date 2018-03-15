#include "BulkQuote.h"

class LimitedQuote : public BulkQuote
{
public:
	LimitedQuote() = default;
	LimitedQuote(const std::string &isbn, double price, float dis, std::size_t max, std::size_t min = 1) : BulkQuote(isbn, price, dis, min), maxQty(max) { }
	virtual ~LimitedQuote() = default;
	virtual std::ostream& debug(std::ostream &out) const override
	{
		BulkQuote::debug(out) << " # maxQty:" << maxQty;
	}
	virtual double netPrice(std::size_t sales) const override
	{
		if(sales > maxQty) return (salesPrice * discount * maxQty) + (sales - maxQty) * salesPrice;
		return salesPrice * discount * sales;
	}

private:
	std::size_t maxQty = 0;
};
