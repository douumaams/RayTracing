#include "shape.hpp"

Shape::Shape(const Point3D& p, const Color& c, const double reflection): _center(p), _color(c), _reflection(reflection)
{}

Shape::~Shape(){}

const Point3D& Shape::getCenter()
{
  return _center;
}
