#include "Query.h"

Query::Query(const std::string &word) : queryType(new WordQuery(word)) { 
#ifndef NDEBUG
	std::cout << "Query::Query(const std::string&)" << std::endl;
#endif
}

Query::Query(const std::shared_ptr<QueryBase> &p) : queryType(p) { 
#ifndef NDEBUG
	std::cout << "Query::Query(const std::shared_ptr<QueryBase>&)" << std::endl;
#endif
}

QueryResult Query::eval(const TextQuery &tq) const { return queryType->eval(tq); }

std::string Query::rep() const { return queryType->rep(); }
