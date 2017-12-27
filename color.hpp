#ifndef __COLOR_HPP__
#define __COLOR_HPP__

class Color
{
	int r, g, b;
public:
	Color() = default;
	Color(Color const& c);
	Color(int rr, int gg, int bb);
	~Color(){};

	/* data */
};


#endif
