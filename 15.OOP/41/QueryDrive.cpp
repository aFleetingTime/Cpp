#include "QueryDrive.h"

QueryDrive::QueryDrive() : opSym { { '|', [](const Query &lhs, const Query &rhs) { return lhs | rhs; } },
								   { '&', [](const Query &lhs, const Query &rhs) { return lhs & rhs; } } } { }

QueryResult QueryDrive::createQuery(const TextQuery &tq, std::string exp)
{
	rmSpace(exp);
	Query temp = resolve(exp, 0, std::string::npos);
	QueryResult result = temp.eval(tq);
	history.addInfo(temp.rep(), temp);
	return result;
}

Query QueryDrive::combination(std::size_t a, std::size_t b, char op)
{
	auto q1 = history.find(a), q2 = history.find(b);
	if(op == '|')
		return q1.second | q2.second;
	if(op == '&')
		return q1.second & q2.second;
	throw std::out_of_range("不支持该运算符!");
}

Query QueryDrive::resolve(const std::string &exp, std::size_t bpos, std::size_t epos) const
{
	if(exp[bpos] == '~')
	{
		std::size_t tpos = exp.find_first_of("&|", ++bpos);
		Query q = ~resolve(exp, bpos, epos);
		if(tpos == epos)
			return q;
		return (*opSym.find(exp[tpos])).second(q, resolve(exp, tpos + 1, epos));
	}
	std::size_t tpos = exp.find_first_of("&|", bpos);
	if(tpos != epos)
		return (*opSym.find(exp[tpos])).second(exp.substr(bpos, tpos - bpos), resolve(exp, tpos + 1, epos));
	return Query(exp.substr(bpos, tpos));
}
