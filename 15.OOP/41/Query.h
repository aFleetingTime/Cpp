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
	friend void swap(Query &, Query &);

public:
	Query(const std::string &);
	Query(const Query &);
	Query(Query &&) noexcept;
	~Query();
	Query& operator=(const Query &);
	Query& operator=(Query &&) noexcept;
	QueryResult eval(const TextQuery &) const;
	std::string rep() const;
	void swap(Query &);

private:
	Query(const QueryBase *);
	const QueryBase *queryType;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query) {
	os << query.rep();
	return os;
}
