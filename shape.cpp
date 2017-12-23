#include "shape.hpp"

Shape::Shape(int x, int y, int z, int r, int g, int b, int reflection)
{
	_center.x = x;
	_center.y = y;
	_center.z = z;
	_color.r = r;
	_color.g = g;
	_color.b = b;
	_reflection = reflection;
};

Shape::~Shape(){};
