#pragma once
#include "QueryBase.h"

class WordQuery : public QueryBase
{
	friend class Query;

private:
	WordQuery(const std::string &);
	QueryResult eval(const TextQuery &) const override;
	std::string rep() const override;
	std::string queryWord;
	virtual operator QueryBase*() const & override;
	virtual operator QueryBase*() && override;
};
