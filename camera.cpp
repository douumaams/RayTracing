#include "camera.hpp"

Camera::Camera(Point3D position, Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background):
_position(position),_screen(top_left, top_right, bottom_left, horizontal_res, background)
{}

Camera::~Camera(){}


std::ostream& operator <<(std::ostream& os, const Camera& camera)
{
	os << camera._screen;
	return os;
}
