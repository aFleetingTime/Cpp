#pragma once
#include <map>
#include <string>
#include "Query.h"
#include "HistoryQuery.h"

namespace Chapter15 {
class QueryDrive final
{
public:
	QueryDrive();
	Chapter10::QueryResult createQuery(const Chapter10::TextQuery &, std::string);
	HistoryQuery& getHistory() { return history; }
	Query combination(std::size_t, std::size_t, char);

private:
	Query resolve(const std::string &, std::size_t, std::size_t) const;
	void rmSpace(std::string &s) const {
		s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
	}
	HistoryQuery history;
	std::map<char, std::function<Query(const Query&, const Query&)>> opSym;
};
}
