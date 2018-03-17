#include "OrQuery.h"

OrQuery::OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {
#ifndef NDEBUG
	std::cout << "OrQuery::OrQuery(const Query&, const Query&)" << std::endl;
#endif
}

QueryResult OrQuery::eval(const TextQuery &tq) const
{
	auto left = lhs.eval(tq), right = rhs.eval(tq);
	auto lineNo = std::make_shared<std::set<line_type>>();
	std::set_union(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*lineNo, lineNo->begin()));
	return { left.getText(), { rep(), lineNo } };
}

Query operator|(const Query &left, const Query &right) {
	return std::shared_ptr<QueryBase>(new OrQuery(left, right));
}
