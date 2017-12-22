#include "shape.hpp"

Shape::Shape(int x, int y, int z)
{
	_center.x = x;
	_center.y = y;
	_center.z = z;
};
Shape::~Shape(){};