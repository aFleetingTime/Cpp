#include "Query.h"

Query::Query(const std::string &word) : queryType(new WordQuery(word)) { }

Query::Query(const std::shared_ptr<QueryBase> &p) : queryType(p) { }

QueryResult Query::eval(const TextQuery &tq) const { return queryType->eval(tq); }

std::string Query::rep() const { return queryType->rep(); }
