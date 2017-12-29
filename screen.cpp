#include "screen.hpp"
#include "vector3D.hpp"

Screen::Screen(Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background):
 _corners{top_left, top_right, bottom_left}, _horizontalRes(horizontal_res), _background_color(background)
{
	int vertical_res = ((bottom_left - top_left).getNorm() / (top_right - top_left).getNorm()) * horizontal_res;

	_pixels.resize(vertical_res);

}

std::ostream& operator <<(std::ostream& os, const Screen& screen)
{
	os << screen.getVerticalResolution() << " " << screen.getHorizontalResultion() << std::endl;
	return os;
}

Point3D Screen::from2Dto3D(int x, int y)
{
	Point3D horizontalOffset = ( _corners[TOP_RIGHT] - _corners[TOP_LEFT] ) / _horizontalRes;
	Point3D verticalOffset = ( _corners[BOTTOM_LEFT] - _corners[TOP_LEFT] ) / ( _corners[BOTTOM_LEFT] - _corners[TOP_LEFT] ).getNorm() * horizontalOffset.getNorm();

	return Point3D(_corners[TOP_LEFT] + x*horizontalOffset + y*verticalOffset);

	// Vector_3d h((topRight - topLeft) / hResolution),
	// 					v((botLeft - topLeft) / (botLeft - topLeft).norm * h.norm);
  //
	// uint32_t vResolution = static_cast<uint32_t>(hResolution * ((botLeft - topLeft).norm / (topRight - topLeft).norm));
	// 				mSensor[y][x] = Pixel(Point(topLeft + h * x + v * y));
}
