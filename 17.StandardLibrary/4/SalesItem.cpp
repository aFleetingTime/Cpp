#include "SalesItem.h"

SalesItem::SalesItem() : SalesItem(std::string("")) {}

SalesItem::SalesItem(std::istream &input) { input >> bookNo >> unitsSold >> revenue; }

SalesItem::SalesItem(const std::string &bNo, size_t sold, double rev) : bookNo(bNo), unitsSold(sold), revenue(rev) {}

SalesItem& SalesItem::operator+=(const SalesItem &sec) { unitsSold += sec.unitsSold; revenue += sec.revenue; return *this; }

SalesItem SalesItem::operator+(const SalesItem &sec) const { return SalesItem(*this) += sec; }

std::string SalesItem::isbn() const { return bookNo; }

bool SalesItem::operator==(const SalesItem &sec) const { return bookNo == sec.bookNo && unitsSold == sec.unitsSold && revenue == sec.revenue; }
bool SalesItem::operator!=(const SalesItem &sec) const { return !(*this == sec); }

double SalesItem::avgPrice() const { return unitsSold ? revenue / unitsSold : 0; }

namespace std
{
	template <>
	class hash<SalesItem>
	{
	public:
		using result_type = size_t;
		using argument_type = SalesItem;
		result_type operator()(const argument_type &s) const noexcept;
	};
	hash<SalesItem>::result_type hash<SalesItem>::operator()(const argument_type &s) const noexcept {
		return hash<string>()(s.bookNo) ^ hash<size_t>()(s.unitsSold) ^ hash<double>()(s.revenue);
	}
}

std::ostream &operator<<(std::ostream &output, const SalesItem &item)
{
	output << item.bookNo << ' ' << item.unitsSold << ' ' << item.revenue << ' ' << item.avgPrice();
	return output;
}

std::istream &operator>>(std::istream &input, SalesItem &item)
{
	if(!input)
		return input;
	input >> item.bookNo >> item.unitsSold >> item.revenue;
	return input;
}

bool compareIsbn(const SalesItem &s1, const SalesItem &s2) {
	return s1.isbn() < s2.isbn();
}

std::vector<Matches> findBook(const std::vector<std::vector<SalesItem>> &files, const std::string &book)
{
	std::vector<Matches> ret;
	for(auto beg = files.cbegin(); beg != files.cend(); ++beg)
	{
		auto p = std::equal_range(beg->cbegin(), beg->cend(), book, compareIsbn);
		if(p.first != p.second)
			ret.emplace_back(beg - files.cbegin(), p.first, p.second);
	}
	return ret;
}
