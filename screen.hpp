#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "util.hpp"

#define TOP_LEFT 0
#define TOP_RIGHT 1
#define BOTTOM_LEFT 2
#define BOTTOM_RIGHT 3

#define HORIZONTAL 0
#define VERTICAL 1

class Screen
{
	public:
		Screen(int horizontal_res, int vertical_res, int tl_corner, int tr_corner, int bl_corner, int br_corner, Color background);
		~Screen();
	private:
		int _resolution[2];
		Position _corners[4];
		// Pixel ** _screen;
		Color _background_color;
};


#endif