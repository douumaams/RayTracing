	#include "color.hpp"


Color::Color(Color const& c):_r(c._r), _g(c._g), _b(c._b) {}

Color::Color(int rr, int gg, int bb): _r(rr), _g(gg), _b(bb) {}

void Color::rGBLimit()
{
			_r = MAX(0, MIN(_r, 255));
			_g = MAX(0, MIN(_g, 255));
			_b = MAX(0, MIN(_b, 255));
}

Color operator*(const Color& c1, const Color& c2)
{
	return Color(c1._r * c2._r, c1._g * c2._g, c1._b * c2._b);
}

Color operator*(const Color& c1, double factor)
{
	return Color(c1._r * factor, c1._g * factor, c1._b * factor);
}

Color operator*(double factor, const Color& c1)
{
	return c1*factor;
}

Color operator/(const Color& c1, double factor)
{
	return Color(c1._r / factor, c1._g / factor, c1._b / factor);
}

Color operator+(const Color& c1, const Color& c2)
{
	return Color(c1._r + c2._r, c1._g + c2._g, c1._b + c2._b);
}

std::ostream& operator<<(std::ostream& os, const Color& p)
{
	auto c = Color(p);
	c.rGBLimit();
	os << (uint32_t)c._r << " " << (uint32_t)c._g << " " << (uint32_t)c._b;
	return os;
}

bool operator==(const Color& c1, const Color& c2)
{
	return c1._r == c2._r && c1._g == c2._g && c1._b == c2._b;
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
