#include "Quote.h"

class DiscQuote : public Quote
{
public:
	DiscQuote() = default;
	DiscQuote(const std::string isbn, double price, float disc, std::size_t qty) : Quote(isbn, price), discount(1.0 - disc), quantity(qty) { }
	DiscQuote(const DiscQuote &rhs) : Quote(rhs), discount(rhs.discount), quantity(rhs.quantity) { }
	DiscQuote(DiscQuote &&rhs) noexcept : Quote(std::move(rhs)), discount(rhs.discount), quantity(rhs.quantity) {
		rhs.quantity = rhs.discount = 0.0;
	}
	virtual ~DiscQuote() = default;
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

protected:
	float discount = 0.0;
	std::size_t quantity = 0;
};
