#include "shape.hpp"

Shape::Shape(const Point3D& p, const Color& c): _center(p), _color(c)
{}

Shape::~Shape(){};
