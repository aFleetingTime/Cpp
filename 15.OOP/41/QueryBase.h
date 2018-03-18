#pragma once
#include "TextQuery.h"

class QueryBase
{
	friend class Query;

protected:
	using line_type = TextQuery::line_type;
	virtual ~QueryBase() = default;
	virtual operator QueryBase*() const & = 0;
	virtual operator QueryBase*() && = 0;

private:
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual std::string rep() const = 0;
};

