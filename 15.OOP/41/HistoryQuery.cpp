#include "HistoryQuery.h"

std::ostream& operator<<(std::ostream &os, const HistoryQuery &hq)
{
	std::size_t lineNo = 0;
	for(const auto &p : hq.info)
		os << '(' << ++lineNo << ") " << p.first << std::endl;
	return os;
}
