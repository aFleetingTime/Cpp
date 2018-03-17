#include "NotQuery.h"

NotQuery::NotQuery(const Query &q) : query(q) { 
#ifndef NDEBUG
	std::cout << "NotQuery::NotQuery(const Query&)" << std::endl;
#endif
}

QueryResult NotQuery::eval(const TextQuery &tq) const
{
	QueryResult result = query.eval(tq);
	std::list<line_type> notQueryList(result.getText()->size());
	std::iota(notQueryList.begin(), notQueryList.end(), 0);
	for(const auto &no : result) {
		notQueryList.remove(no);
	}
	std::shared_ptr<std::set<line_type>> lineNo = std::make_shared<std::set<line_type>>(notQueryList.cbegin(), notQueryList.cend());
	return QueryResult(result.getText(), { rep(), lineNo });
}

std::string NotQuery::rep() const {
	return "~(" + query.rep() + ")";
}

Query operator~(const Query &query) {
	return std::shared_ptr<QueryBase>(new NotQuery(query));
}
