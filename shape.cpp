#include "shape.hpp"

Shape::Shape(int x, int y, int z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
};
Shape::~Shape(){};