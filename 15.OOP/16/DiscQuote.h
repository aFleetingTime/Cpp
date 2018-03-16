#include "Quote.h"

class DiscQuote : public Quote
{
public:
	DiscQuote() = default;
	DiscQuote(const std::string isbn, double price, float disc, std::size_t qty) : Quote(isbn, price), discount(disc), quantity(qty) { }
	virtual ~DiscQuote() = default;
	virtual double netPrice(std::size_t sales) const = 0;

protected:
	float discount = 0.0;
	std::size_t quantity = 0;
};
