#include "point3D.hpp"

Point3D::Point3D(Point3D const& p):
_x(p._x), _y(p._y), _z(p._z)
{}


Point3D::Point3D(double xx, double yy, double zz):
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

Point3D operator*(const Point3D& p1, const Point3D& p2)
{
	return Point3D(p1._x * p2._x, p1._y * p2._y, p1._z * p2._z);
}

Point3D operator/(const Point3D& p1, const Point3D& p2)
{
	return Point3D(p1._x / p2._x, p1._y / p2._y, p1._z / p2._z);
}




Point3D operator*(const Point3D& p1, double factor)
{
	return Point3D(p1._x * factor, p1._y * factor, p1._z * factor);
}

Point3D operator*(double factor, const Point3D& p1)
{
	return p1*factor;
}

Point3D operator/(const Point3D& p1, double factor)
{
	return Point3D(p1._x / factor, p1._y / factor, p1._z / factor);
}

std::ostream& operator<<(std::ostream& os, const Point3D& p)
{
	os << p._x << " " << p._y << " " << p._z;
	return os;
}

Point3D& Point3D::operator=(const Point3D& p1)
{
	if(&p1 != this)
	{
		_x = p1._x;
		_y = p1._y;
		_z = p1._z;
	}

	return *this;
}
