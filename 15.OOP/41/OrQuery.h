#pragma once
#include "BinaryQuery.h"
#include <iterator>

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);

private:
	OrQuery(const Query &, const Query &);
	QueryResult eval(const TextQuery &) const override;
	virtual operator QueryBase*() const & override;
	virtual operator QueryBase*() && override;
};
