#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <vector>
#include <utility>
#include "point3D.hpp"
#include "color.hpp"
#include "pixel.hpp"


#define TOP_LEFT 0
#define TOP_RIGHT 1
#define BOTTOM_LEFT 2
#define BOTTOM_RIGHT 3

#define HORIZONTAL 0
#define VERTICAL 1

class Screen
{
	public:
		Screen(){};
		// Screen(int horizontal_res, int vertical_res, int tl_corner, int tr_corner, int bl_corner, int br_corner, Color background);
		// Screen(Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background);
		~Screen(){};
		// int getVerticalResolution() const { return _screen}
		// int getHorizontalResultion() const {return _screen.}
	private:
		// on doit avoir un tableau de pixel
		// la resolution representra la longueur et largeur
		// la couleur de fond va dependre du pixel a l'instanciation
		// Pixel ** _screen;
		// Color _background_color;
		std::vector<std::vector<Pixel>> _screen;
};


#endif		