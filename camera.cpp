#include "camera.hpp"

Camera::Camera(int x, int y, int z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}
Camera::~Camera(){}