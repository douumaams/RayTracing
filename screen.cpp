#include "screen.hpp"
#include "vector3D.hpp"
#include <iostream>

Screen::Screen(Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background):
 _corners{top_left, top_right, bottom_left}, _horizontalRes(horizontal_res), _background_color(background)
{
	int vertical_res = ((bottom_left - top_left).getNorm() / (top_right - top_left).getNorm()) * horizontal_res;

	_pixels.resize(vertical_res);
	std::cout << "resolution vertical : " << vertical_res << std::endl;

	for (int i = 0; i < vertical_res; i++)
	{
		for (int j = 0; j < horizontal_res; j++)
		{
			_pixels[i].push_back(Pixel(from2Dto3D(i, j), _background_color));
		}
	}

}

std::ostream& operator <<(std::ostream& os, const Screen& screen)
{
	os << screen.getVerticalResolution()<< " " << screen.getHorizontalResultion() << std::endl;
	os << 255 << std::endl;

	for (int i = 0; i < screen.getVerticalResolution(); i++)
	{
		for (int j = 0; j < screen.getHorizontalResultion(); j++)
		{
			os << screen._pixels[j][i] << " ";
		}
    os << std::endl;
	}
	return os;
}

Point3D Screen::from2Dto3D(int x, int y)
{
	Point3D horizontalOffset = ( _corners[TOP_RIGHT] - _corners[TOP_LEFT] ) / _horizontalRes;
	Point3D verticalOffset = ( _corners[BOTTOM_LEFT] - _corners[TOP_LEFT] ) / ( _corners[BOTTOM_LEFT] - _corners[TOP_LEFT] ).getNorm() * horizontalOffset.getNorm();
	return Point3D(_corners[TOP_LEFT] + x * horizontalOffset + y * verticalOffset);
}

void Screen::setColor(const Color& color, int verticalPos, int horizontalPos)
{
  _pixels[verticalPos][horizontalPos].setColor(color);
}
