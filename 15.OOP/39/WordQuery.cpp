#include "WordQuery.h"
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"

WordQuery::WordQuery(const std::string &word) : queryWord(word) { 
#ifndef NDEBUG
	std::cout << "WordQuery::WordQuery(const std::string&)" << std::endl;
#endif
}

QueryResult WordQuery::eval(const TextQuery &tq) const { 
	return tq.query(queryWord); 
}

std::string WordQuery::rep() const { 
	return queryWord; 
}
