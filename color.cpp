	#include "color.hpp"


Color::Color(Color const& c):_r(c._r), _g(c._g), _b(c._b) {}

Color::Color(int rr, int gg, int bb): _r(rr), _g(gg), _b(bb) {}


Color operator*(const Color& c1, const Color& c2)
{
	return Color(c1._r * c2._r, c1._g * c2._g, c1._b * c2._b);
}


Color operator*(const Color& c1, double factor)
{
	Color returnValue;
	returnValue._r = c1._r * factor;
	returnValue._g = c1._g * factor;
	returnValue._b = c1._b * factor;
	return returnValue;
}

Color operator*(double factor, const Color& c1)
{
	return c1*factor;
}

Color operator/(const Color& c1, double factor)
{
	Color returnValue;
	returnValue._r = c1._r / factor;
	returnValue._g = c1._g / factor;
	returnValue._b = c1._b / factor;
	return returnValue;
}

Color operator/(double factor, const Color& c1)
{
	Color returnValue;
	returnValue._r = factor / c1._r;
	returnValue._g = factor / c1._g;
	returnValue._b = factor / c1._b;
	return returnValue;
}

std::ostream& operator<<(std::ostream& os, const Color& p)
{
	os << p._r << " " << p._g << " " << p._b;
	return os;
}

Color& Color::operator=(const Color& c1)
{
	if(&c1 != this)
	{
		_r = c1._r;
		_g = c1._g;
		_b = c1._b;
	}
	return *this;
}
