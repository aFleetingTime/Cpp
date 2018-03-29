#include "Token.h"
#include <iostream>

Token::Token() noexcept : tok(INT) { }
Token::~Token() { checkType(); }
Token::Token(const Token &rhs) noexcept : tok(rhs.tok) { copyUnion(rhs); }
Token::Token(Token &&rhs) noexcept : tok(rhs.tok) { copyUnion(rhs); }
Token& Token::operator=(const Token &rhs) noexcept
{
	if(tok == STR && rhs.tok == STR)
		cmdCopy(const_cast<std::string&>(rhs.sval));
	else
	{
		checkType(rhs.tok != STR);
		copyUnion(rhs, &Token::cmdCopy);
	}
	tok = rhs.tok;
	return *this;
}
Token& Token::operator=(Token &&rhs) noexcept
{
	if(tok == STR && rhs.tok == STR)
		cmdMove(rhs.sval);
	else
	{
		checkType(rhs.tok != STR);
		copyUnion(rhs, &Token::cmdMove);
	}
	tok = rhs.tok;
	return *this;
}

Token& Token::operator=(char c) noexcept
{
	checkType();
	cval = c;
	tok = CHAR;
	return *this;
}
Token& Token::operator=(int i) noexcept
{
	checkType();
	ival = i;
	tok = INT;
	return *this;
}
Token& Token::operator=(double d) noexcept
{
	checkType();
	dval = d;
	tok = DBL;
	return *this;
}
Token& Token::operator=(const std::string &s) noexcept
{
	if(tok == STR) sval = s;
	else cmdCopy(const_cast<std::string&>(s));
	tok = STR;
	return *this;
}
Token& Token::operator=(std::string &&s) noexcept
{
	if(tok == STR) sval = s;
	else cmdMove(s);
	tok = STR;
	return *this;
}

void Token::copyUnion(const Token &rhs, CmdType cmd) noexcept
{
	switch(rhs.tok)
	{
		case CHAR: cval = rhs.cval; break;
		case INT: ival = rhs.ival; break;
		case DBL: dval = rhs.dval; break;
		case STR: (this->*cmd)(const_cast<std::string&>(rhs.sval)); break;
	}
}
void Token::checkType(bool rhs) const noexcept {
	if(tok == STR && rhs) sval.~basic_string();
}
void Token::cmdCopy(std::string &s) noexcept {
	new (&sval) std::string(s);
}
void Token::cmdMove(std::string &s) noexcept {
	new (&sval) std::string(std::move(s));
}
const void* Token::getValue() const noexcept {
	return &cval;
}
Token::operator const void*() const noexcept {
	return &cval;
}
