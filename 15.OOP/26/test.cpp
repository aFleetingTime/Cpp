#include <iostream>
#include "Quote.h"
#include "BulkQuote.h"
#include "LimitedQuote.h"

double printTotal(std::ostream &out, const Quote &quote, std::size_t sales)
{
	double price = quote.netPrice(sales);
	out << "ISBN: " << quote.isbn() << "\nPrice: " << price << std::endl;
	return price;
}

std::ostream& debugQuote(std::ostream &out, const Quote &quote)
{
	out << typeid(quote).name() << "  ";
	quote.debug(out) << std::endl;
	return out;
}

int main()
{
	// cannot declare variable ‘test’ to be of abstract type ‘DiscQuote’
	// DiscQuote test;
	Quote quote("1665X564AA54D", 55);
	BulkQuote bulk("456AS4512587F", 55, 0.5, 6);
	Quote q(std::move(quote));
	quote = bulk;
	printTotal(std::cout, quote, 1);
}
