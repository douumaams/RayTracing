#ifndef __pixels_H__
#define __pixels_H__

#include <vector>
#include <utility>
#include "point3D.hpp"
#include "color.hpp"
#include "pixel.hpp"
#include <ostream>

#define TOP_LEFT 0
#define TOP_RIGHT 1
#define BOTTOM_LEFT 2

class Screen
{
	private:
		Point3D _corners[3];
		int _horizontalRes;
		Color _background_color;
		std::vector<std::vector<Pixel>> _pixels;

	public:
		Screen() = default;
		Screen(Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background);
		virtual ~Screen(){};

		Point3D from2Dto3D(int x, int y);

		int getVerticalResolution() const { return _pixels.size();}
		int getHorizontalResultion() const {return _pixels[0].size();}
		void setColor(const Color& color, int verticalPos, int horizontalPos);

		std::vector<std::vector<Pixel>>& getPixels() { return _pixels;};
		Color getBackgroundColor() const {return _background_color;};
		Pixel& getPixel(int x, int y) {return _pixels[x][y];};

		friend std::ostream& operator <<(std::ostream& os, const Screen& screen);
};


#endif
