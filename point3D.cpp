#include "point3D.hpp"

Point3D::Point3D(Point3D const& p):
_x(p._x), _y(p._y), _z(p._z)
{}


Point3D::Point3D(int xx, int yy, int zz):
_x(xx), _y(yy), _z(zz)
{}

Point3D::~Point3D(){}



Point3D operator-(const Point3D& p1, const Point3D& p2)
{
	return Point3D(p1._x - p2._x, p1._y - p2._y, p1._z - p2._z);
}

Point3D operator+(const Point3D& p1, const Point3D& p2)
{
	return Point3D(p1._x + p2._x, p1._y + p2._y, p1._z + p2._z);
}

std::ostream& operator<<(std::ostream& os, const Point3D& p)
{
	os << p._x << " " << p._y << " " << p._z;
	return os;
}
