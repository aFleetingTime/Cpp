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
	LimitedQuote lim("18FAS8495SFA", 55, 0.5, 6);
	printTotal(std::cout, quote, 10);
	printTotal(std::cout, bulk, 10);
	printTotal(std::cout, lim, 10);
	std::cout << "---------------" << std::endl;
	debugQuote(std::cout, quote);
	debugQuote(std::cout, bulk);
	debugQuote(std::cout, lim);
}
