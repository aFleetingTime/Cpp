#pragma once
#include "Query.h"
#include "WordQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <memory>
#include <string>

class Query
{
	friend Query operator~(const Query &);
	friend Query operator&(const Query &, const Query &);
	friend Query operator|(const Query &, const Query &);
public:
	Query(const std::string &);
	QueryResult eval(const TextQuery &) const;
	std::string rep() const;
private:
	Query(const std::shared_ptr<QueryBase> &);
	std::shared_ptr<QueryBase> queryType;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query) {
	os << query.rep();
	return os;
}
