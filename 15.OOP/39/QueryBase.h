#pragma once
#include "TextQuery.h"

class QueryBase
{
	friend class Query;

protected:
	using line_type = TextQuery::line_type;
	virtual ~QueryBase() = default;
	QueryBase() {
#ifndef NDEBUG
		std::cout << "QueryBase::QueryBase()" << std::endl;
#endif
	}

private:
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual std::string rep() const = 0;
};

