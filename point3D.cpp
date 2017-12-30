#include "point3D.hpp"

Point3D::Point3D(Point3D const& p):
_x(p._x), _y(p._y), _z(p._z)
{}


Point3D::Point3D(double xx, double yy, double zz):
_x(xx), _y(yy), _z(zz)
{}

Point3D::~Point3D(){}

Point3D operator-(const Point3D& v1, const Point3D& v2)
{
	return Point3D(v1._x - v2._x, v1._y - v2._y, v1._z - v2._z);
}

Point3D operator+(const Point3D& v1, const Point3D& v2)
{
	return Point3D(v1._x + v2._x, v1._y + v2._y, v1._z + v2._z);
}

Point3D operator*(const Point3D& v1, const Point3D& v2)
{
	return Point3D(v1._x * v2._x, v1._y * v2._y, v1._z * v2._z);
}

Point3D operator/(const Point3D& v1, const Point3D& v2)
{
	return Point3D(v1._x / v2._x, v1._y / v2._y, v1._z / v2._z);
}




Point3D operator*(const Point3D& v1, double factor)
{
	Point3D returnValue;
	returnValue._x = v1._x * factor;
	returnValue._y = v1._y * factor;
	returnValue._z = v1._z * factor;
	return returnValue;
}

Point3D operator*(double factor, const Point3D& v1)
{
	return v1*factor;
}

Point3D operator/(const Point3D& v1, double factor)
{
	Point3D returnValue;
	returnValue._x = v1._x / factor;
	returnValue._y = v1._y / factor;
	returnValue._z = v1._z / factor;
	return returnValue;
}

Point3D operator/(double factor, const Point3D& v1)
{
	return v1/factor;
}

std::ostream& operator<<(std::ostream& os, const Point3D& p)
{
	os << p._x << " " << p._y << " " << p._z;
	return os;
}

Point3D& Point3D::operator=(const Point3D& v1)
{
	_x = v1._x;
	_y = v1._y;
	_z = v1._z;

	return *this;
}
