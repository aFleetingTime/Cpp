#pragma once
#include <string>

template <typename T>
T* to_pointer(void *p) {
	return static_cast<T*>(p);
}
template <typename T>
const T* to_pointer(const void *p) {
	return static_cast<const T*>(p);
}

class Token final
{
public:
	enum Types { CHAR, INT, DBL, STR };
	Token() noexcept;
	~Token();
	Token(const Token &) noexcept;
	Token(Token &&) noexcept;
	Token& operator=(const Token &) noexcept;
	Token& operator=(Token &&) noexcept;

	Token& operator=(char) noexcept;
	Token& operator=(int) noexcept;
	Token& operator=(double) noexcept;
	Token& operator=(const std::string &) noexcept;
	Token& operator=(std::string &&) noexcept;
	operator const void*() const noexcept;
	const void* getValue() const noexcept;

private:
	using CmdType = void (Token::*)(std::string &);
	Types tok;
	union { 
		char cval;
		int ival;
		double dval;
		std::string sval;
	};
	void copyUnion(const Token &, CmdType cmd = &Token::cmdCopy) noexcept;
	void checkType(bool rhs = true) const noexcept;
	void cmdCopy(std::string &) noexcept;
	void cmdMove(std::string &) noexcept;
};
