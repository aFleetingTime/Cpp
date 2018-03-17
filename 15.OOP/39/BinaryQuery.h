#pragma once
#include "Query.h"

class BinaryQuery : public QueryBase
{
protected:
	BinaryQuery(const Query &left, const Query &right, const std::string &op);
	virtual std::string rep() const override final;
	Query lhs, rhs;
	std::string opSym;
};

inline BinaryQuery::BinaryQuery(const Query &left, const Query &right, const std::string &op) : lhs(left), rhs(right), opSym(op) { 
#ifndef NDEBUG
	std::cout << "BinaryQuery::BinaryQuery(const Query&, const Query&, const std::string&)" << std::endl;
#endif
}

inline std::string BinaryQuery::rep() const {
	return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
}
