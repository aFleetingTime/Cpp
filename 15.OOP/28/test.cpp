#include <iostream>
#include <memory>
#include <functional>
#include <numeric>
#include <vector>
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
	constexpr std::size_t sales = 5;
#ifndef SHARED
	Quote quote("A", 25);
	BulkQuote bulk("A", 6, 0.7, 3);
	LimitedQuote limited("A", 25, 0.5, 3);

	std::vector<Quote> qvec { quote, bulk, limited };

	std::cout << "Quote's total: " << (quote.netPrice(sales) + bulk.netPrice(sales) + limited.netPrice(sales)) << std::endl;
	std::cout << "Vector Quote's total: " << std::accumulate(qvec.cbegin(), qvec.cend(), 0.0, [sales](const double &sum, const Quote &quote) {
		return sum + quote.netPrice(sales);
	}) << std::endl;
#else
	std::vector<std::shared_ptr<Quote>> pvec { std::make_shared<Quote>("A", 25),
											   std::make_shared<BulkQuote>("B", 6, 0.7, 3),
											   std::make_shared<LimitedQuote>("C", 25, 0.5, 3) };
	std::cout << "Vector Quote's total: " << std::accumulate(pvec.cbegin(), pvec.cend(), 0.0, [sales](const double &sum, const std::shared_ptr<Quote> p) {
		return sum + p->netPrice(sales);
	}) << std::endl;
#endif
}
