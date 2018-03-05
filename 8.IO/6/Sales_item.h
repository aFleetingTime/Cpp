#include <iostream>
#include <string>

class Sales_item
{
	friend std::ostream &operator<<(std::ostream &, const Sales_item &item);
	friend std::istream &operator>>(std::istream &, Sales_item &item);
public:
	Sales_item() : Sales_item(std::string("")) {}
	Sales_item(std::istream &input) { input >> bookNo >> unitsSold >> revenue; }
	Sales_item(const std::string &bNo, size_t sold = 0, double rev = 0.0) : bookNo(bNo), unitsSold(sold), revenue(rev) {}
	Sales_item &operator+=(const Sales_item &sec) { unitsSold += sec.unitsSold; revenue += sec.revenue; return *this; }
	Sales_item operator+(const Sales_item &sec) const { return Sales_item(*this) += sec; }

	std::string isbn() const { return bookNo; }

	bool operator==(const Sales_item &sec) const { return bookNo == sec.bookNo && unitsSold == sec.unitsSold && revenue == sec.revenue; }
	bool operator!=(const Sales_item &sec) const { return !(*this == sec); }

	double avgPrice() const { return unitsSold ? revenue / unitsSold : 0; }

private:
	std::string bookNo;
	size_t unitsSold;
	double revenue;
};

inline std::ostream &operator<<(std::ostream &output, const Sales_item &item)
{
	output << item.bookNo << ' ' << item.unitsSold << ' ' << item.revenue << ' ' << item.avgPrice();
	return output;
}

inline std::istream &operator>>(std::istream &input, Sales_item &item)
{
	if(!input)
		return input;
	input >> item.bookNo >> item.unitsSold >> item.revenue;
	return input;
}
