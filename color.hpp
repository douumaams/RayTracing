#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <ostream>

class Color
{
private:
	int _r, _g, _b;
public:
	Color() = default;
	Color(Color const& c);
	Color(int rr, int gg, int bb);
	~Color(){};

	void setR(int r) { _r = r;};
	void setG(int g) { _g = g;};
	void setB(int b) { _b = b;};

	void bound();

	friend Color operator*(const Color& c1, const Color& c2);

	friend Color operator/(const Color& c1, double factor);
	friend Color operator*(const Color& c1, double factor);
	friend Color operator/(double factor, const Color& c1);
	friend Color operator*(double factor, const Color& c1);

	friend std::ostream& operator<<(std::ostream& os, const Color& c);

	Color& operator=(const Color& c1);
};


#endif
