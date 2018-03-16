#include <set>
#include <memory>
#include "Quote.h"

class Basket
{
public:
	using ItemType = std::shared_ptr<Quote>;
	void addItem(Quote *item, std::size_t n = 1)
	{
		std::shared_ptr<Quote> ptr(item);
		ptr->addSold(n);
		auto temp = items.find(ptr);
		if(temp == items.end()) items.emplace(ptr);
		else (*temp)->addSold(*ptr);
	}
	double totalReceipt(std::ostream &os)
	{
		return std::accumulate(items.cbegin(), items.cend(), 0.0, [&os](const double &sum, const ItemType &item) {
			return sum + Quote::printTotal(os, *item);
		});
	}
private:
	static bool compare(const ItemType &lhs, const ItemType &rhs) { return lhs->isbn() < rhs->isbn(); }
	std::set<ItemType, decltype(compare)*> items { compare };
};
