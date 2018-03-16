#include "Quote.h"

class DiscQuote : public Quote
{
public:
	DiscQuote() {
		std::cout << "DiscQuote()" << std::endl;
	}
	DiscQuote(const std::string isbn, double price, float disc, std::size_t qty) : Quote(isbn, price), discount(disc), quantity(qty) {
		std::cout << "DiscQuote(isbn, price, disc, qty)" << std::endl;
	}
	DiscQuote(const DiscQuote &rhs) {
		std::cout << "DiscQuote()" << std::endl;
	}
	DiscQuote(DiscQuote &&rhs) noexcept : Quote(std::move(rhs)), discount(rhs.discount), quantity(rhs.quantity) {
		quantity = discount = 0.0;
		std::cout << "DiscQuote()" << std::endl;
	}
	virtual ~DiscQuote() {
		std::cout << "~DiscQuete()" << std::endl;
	}
	DiscQuote& operator=(const DiscQuote &rhs) {
		Quote::operator=(rhs);
		discount = rhs.discount;
		quantity = rhs.quantity;
		std::cout << "operator=(DiscQuote&)" << std::endl;
	}
	DiscQuote& operator=(DiscQuote &&rhs) noexcept {
		Quote::operator=(std::move(rhs));
		discount = rhs.discount;
		quantity = rhs.quantity;
		quantity = discount = 0.0;
		std::cout << "operator=(DiscQuote&&)" << std::endl;
	}
	virtual double netPrice(std::size_t sales) const = 0;

protected:
	float discount = 0.0;
	std::size_t quantity = 0;
};
