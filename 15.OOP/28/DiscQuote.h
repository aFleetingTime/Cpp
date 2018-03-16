#include "Quote.h"

class DiscQuote : public Quote
{
public:
	DiscQuote() { }
	DiscQuote(const std::string isbn, double price, float disc, std::size_t qty) : Quote(isbn, price), discount(disc), quantity(qty) { }
	DiscQuote(const DiscQuote &rhs) { }
	DiscQuote(DiscQuote &&rhs) noexcept : Quote(std::move(rhs)), discount(rhs.discount), quantity(rhs.quantity) {
		quantity = discount = 0.0;
	}
	virtual ~DiscQuote() { }
	DiscQuote& operator=(const DiscQuote &rhs) {
		Quote::operator=(rhs);
		discount = rhs.discount;
		quantity = rhs.quantity;
	}
	DiscQuote& operator=(DiscQuote &&rhs) noexcept {
		Quote::operator=(std::move(rhs));
		discount = rhs.discount;
		quantity = rhs.quantity;
		quantity = discount = 0.0;
	}
	virtual double netPrice(std::size_t sales) const = 0;

protected:
	float discount = 0.0;
	std::size_t quantity = 0;
};
