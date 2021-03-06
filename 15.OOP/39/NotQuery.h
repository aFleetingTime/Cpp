#include "Query.h"
#include <list>
#include <numeric>

class NotQuery : public QueryBase
{
	friend class Query;
	friend Query operator~(const Query &);

private:
	NotQuery(const Query &);
	QueryResult eval(const TextQuery &) const override;
	std::string rep() const override;
	Query query;
	std::shared_ptr<QueryBase> p;
};
