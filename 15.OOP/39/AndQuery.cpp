#include "AndQuery.h"

AndQuery::AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {
#ifndef NDEBUG
	std::cout << "AndQuery::AndQuery(const Query&, const Query&)" << std::endl;
#endif
}

QueryResult AndQuery::eval(const TextQuery &tq) const
{
	auto leftLine = lhs.eval(tq), rightLine = rhs.eval(tq);
	auto lineNo = std::make_shared<std::set<line_type>>();
	std::set_intersection(leftLine.begin(), leftLine.end(), rightLine.begin(), rightLine.end(), std::inserter(*lineNo, lineNo->begin()));
	return { leftLine.getText(), { rep(), lineNo } };
}

Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}
