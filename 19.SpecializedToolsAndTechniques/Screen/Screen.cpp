#include "Screen.h"

const std::array<Screen::ActionType, Screen::DOWN + 1> Screen::menu {
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down
};

Screen::Screen() : cursor(0) { }
Screen::Screen(pos rw, pos cl, char c, pos b) : contents(rw * cl, c), row(rw), col(cl), cursor(b) { }

Screen& Screen::setColor(std::ostream &os, Color c) {
	os << c.toColor();
	return *this;
}

Screen::pos Screen::current() const noexcept { return cursor; }
char Screen::get() const 
{ 
	rangeCheck();
	return contents[cursor++];
}
char Screen::get(pos index) const
{
	rangeCheck();
	return contents[index];
}
char Screen::getCursor() const
{
	rangeCheck();
	return contents[cursor];
}
Screen& Screen::set(char c)
{
	rangeCheck();
	contents[cursor++] = c;
	return *this;
}
Screen& Screen::setCursor(char c)
{
	rangeCheck();
	contents[cursor] = c;
	return *this;
}
Screen& Screen::replace(const std::string &newContents)
{
	if(newContents.size() > contents.size())
		throw std::length_error("new contents > old contentslength");
	std::copy(newContents.cbegin(), newContents.cend(), contents.begin());
	return *this;
}
Screen& Screen::move(Directions d, pos len) { return (this->*menu[d])(len); }
Screen& Screen::home(pos len)
{
	cursor = row * col - 1;
	return *this;
}
Screen& Screen::forward(pos len)
{
	cursor += len;
	rangeCheck();
	return *this;
}
Screen& Screen::back(pos len)
{
	cursor -= len;
	rangeCheck();
	return *this;
}
Screen& Screen::up(pos len)
{
	cursor -= len * row;
	rangeCheck();
	return *this;
}
Screen& Screen::down(pos len)
{
	cursor += len * row;
	rangeCheck();
	return *this;
}
void Screen::rangeCheck() const
{
	if(cursor >= contents.size())
		throw std::out_of_range("'cursor' out of range");
}


Screen::operator bool() const { return cursor < contents.size(); }
char& Screen::operator[](pos index)
{
	rangeCheck();
	return contents[index];
}
const char& Screen::operator[](pos index) const
{
	rangeCheck();
	return contents[index];
}
std::ostream& operator<<(std::ostream &os, const Screen &screen)
{
	std::string buf;
	for(Screen::pos len = 0; len != screen.col * screen.row; len += screen.row)
		(buf += screen.contents.substr(len, screen.row)).push_back('\n');
	return os << buf;
}
