#include "screen.hpp"
#include "vector3D.hpp"

Screen::Screen(Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background):
_background_color(background)
{
	int vertical_res = ((bottom_left - top_left).getNorm() / (top_right - top_left).getNorm()) * horizontal_res;

	_screen.resize(vertical_res);

}

std::ostream& operator <<(std::ostream& os, const Screen& screen)
{
	os << screen.getVerticalResolution() << " " << screen.getHorizontalResultion() << std::endl;
	return os;
}


