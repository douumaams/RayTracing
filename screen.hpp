#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <vector>
#include <utility>
#include "point3D.hpp"
#include "color.hpp"
#include "pixel.hpp"
#include <ostream>

class Screen
{
	private:
		Color _background_color;
		std::vector<std::vector<Pixel>> _screen;
	public:
		Screen() = default;
		Screen(Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background);
		virtual ~Screen(){};
		int getVerticalResolution() const { return _screen.size();}
		int getHorizontalResultion() const {return _screen[0].size();}

		friend std::ostream& operator <<(std::ostream& os, const Screen& screen);

};


#endif
