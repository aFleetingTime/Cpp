#include <iostream>
#include <memory>
#include <functional>
#include <numeric>
#include <vector>
#include "Quote.h"
#include "BulkQuote.h"
#include "LimitedQuote.h"
#include "Basket.h"

int main()
{
	Basket basket;	
	Quote q1("C++ Primer", 99);
	BulkQuote q2("Effective C++", 45, 0.2, 2);
	LimitedQuote q3("APUE", 85, 0.3, 5);
	basket.addItem(q1);
	basket.addItem(q2, 2);
	basket.addItem(q3, 6);
	basket.addItem(BulkQuote("More", 40, 0.1, 1), 1);
	double total = basket.totalReceipt(std::cout);
	std::cout << "Total: " << total << std::endl;
}
