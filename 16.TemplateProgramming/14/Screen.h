#include <iostream>
#include <string>

using Pos = std::string::size_type;
template <Pos H, Pos W> class Screen;

template <Pos H, Pos W> std::ostream& operator<<(std::ostream &, const Screen<H, W> &);
template <Pos H, Pos W> std::istream& operator>>(std::istream &, Screen<H, W> &);

template <Pos H, Pos W>
class Screen final
{
	friend std::ostream& operator<<<H, W>(std::ostream &, const Screen<H, W> &);
	friend std::istream& operator>><H, W>(std::istream &, Screen<H, W> &);

public:
	Screen(char c = '*');
	Screen& move(Pos row, Pos col);
	Screen& set(Pos row, Pos col, char c);
	Screen& set(char c);
	char get() const;
	char get(Pos row, Pos col) const;
	Pos next();
	operator bool();

private:
	Pos cursor = 0;
	std::string contents;
};

template <Pos H, Pos W>
Screen<H, W>::operator bool() { return cursor != H * W; }

template <Pos H, Pos W>
Screen<H, W>::Screen(char c) : contents(H * W, c) { }

template <Pos H, Pos W>
Screen<H, W>& Screen<H, W>::move(Pos row, Pos col) 
{
	cursor = row * col; 
	return *this;
}

template <Pos H, Pos W>
Screen<H, W>& Screen<H, W>::set(Pos row, Pos col, char c)
{
	contents.at(row * W + col) = c; 
	return *this;
}

template <Pos H, Pos W>
Screen<H, W>& Screen<H, W>::set(char c)
{
	contents.at(cursor) = c;
	return *this;
}

template <Pos H, Pos W>
char Screen<H, W>::get() const
{
	return contents.at(cursor);
}

template <Pos H, Pos W>
char Screen<H, W>::get(Pos row, Pos col) const
{
	return contents.at(row * H + col);
}

template <Pos H, Pos W>
Pos Screen<H, W>::next()
{
	return ++cursor;
}

template <Pos H, Pos W>
std::ostream& operator<<(std::ostream &os, const Screen<H, W> &screen)
{
	for(Pos row = 0; row != H; ++row)
	{
		for(Pos col = 0; col != W; ++col)
			os << screen.get(row, col);
		os << std::endl;
	}
	return os;
}

template <Pos H, Pos W>
std::istream& operator>>(std::istream &is, Screen<H, W> &screen)
{
	std::string input;
	is >> input;
	for(const char &c : input)
	{
		screen.set(c);
		screen.next();
	}
	return is;
}
