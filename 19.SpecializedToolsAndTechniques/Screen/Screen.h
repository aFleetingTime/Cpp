#pragma once
#include <iostream>
#include <string>
#include <array>
#include <sstream>

class Screen final
{
	friend std::ostream& operator<<(std::ostream &, const Screen &);
public:
	using pos = std::string::size_type;
	using ActionType = Screen& (Screen::*)(Screen::pos);
	using getType = char (Screen::*)() const;

	enum Directions { HOME, FORWARD, BACK, UP, DOWN };

	Screen();
	Screen(pos, pos, char c = '*', pos b = 0);

	char get() const;
	char get(pos) const;
	char getCursor() const;
	pos current() const noexcept;
	Screen& set(char);
	Screen& setCursor(char);
	Screen& replace(const std::string &);
	Screen& move(Directions, pos len = 1);
	Screen& home(pos);
	Screen& forward(pos);
	Screen& back(pos);
	Screen& up(pos);
	Screen& down(pos);

	explicit operator bool() const;
	char& operator[](pos);
	const char& operator[](pos) const;
private:
	std::string contents;
	mutable pos cursor;
	pos row, col;
	static const std::array<ActionType, DOWN + 1> menu;
	void rangeCheck() const;
};
