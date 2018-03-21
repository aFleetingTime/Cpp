#pragma once
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class SalesItem;
using Matches = std::tuple<std::vector<SalesItem>::size_type,
						   std::vector<SalesItem>::const_iterator,
						   std::vector<SalesItem>::const_iterator>;

template <typename T> class hash;
std::ostream &operator<<(std::ostream &, const SalesItem &item);
std::istream &operator>>(std::istream &, SalesItem &item);

class SalesItem
{
	friend std::ostream &operator<<(std::ostream &, const SalesItem &item);
	friend std::istream &operator>>(std::istream &, SalesItem &item);
	friend class std::hash<SalesItem>;
	
public:
	SalesItem();
	SalesItem(std::istream &input);
	SalesItem(const std::string &bNo, size_t sold = 0, double rev = 0.0);
	SalesItem &operator+=(const SalesItem &sec);
	SalesItem operator+(const SalesItem &sec) const;

	std::string isbn() const;

	bool operator==(const SalesItem &sec) const;
	bool operator!=(const SalesItem &sec) const;

	double avgPrice() const;

private:
	std::string bookNo;
	size_t unitsSold;
	double revenue;
};

std::vector<Matches> findBook(const std::vector<std::vector<SalesItem>> &files, const std::string &book);
