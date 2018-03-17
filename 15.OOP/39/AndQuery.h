#pragma once
#include "BinaryQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <algorithm>

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);

private:
	AndQuery(const Query &, const Query &);
	QueryResult eval(const TextQuery &) const override;
};
