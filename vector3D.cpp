#include "vector3D.hpp"
#include <iostream>

Vector3D::Vector3D(Vector3D const& p):
_x(p._x), _y(p._y), _z(p._z)
{
	normalize();
}


Vector3D::Vector3D(double xx, double yy, double zz):
_x(xx), _y(yy), _z(zz)
{
	// normalize();
}

Vector3D::~Vector3D(){}


double Vector3D::scalarProduct(const Vector3D& v)
{
	return (this->_x * v.getX()) + (this->_y * v.getY()) + (this->_z * v.getZ());
}

Vector3D* Vector3D::createVector(const Point3D& origin, const Point3D& arrival)
{
  double dx = arrival.getX() - origin.getX();

  double dy = arrival.getY() - origin.getY();

  double dz = arrival.getZ() - origin.getZ();

  return new Vector3D(dx, dy, dz);
}


bool operator==(const Vector3D& v1, const Vector3D& v2)
{
	return (v1._x == v2._x) && (v1._y == v2._y) && (v1._z == v2._z);
}

bool operator!=(const Vector3D& v1, const Vector3D& v2)
{
	return (v1._x != v2._x) && (v1._y != v2._y) && (v1._z != v2._z);
}

Vector3D operator-(const Vector3D& v1, const Vector3D& v2)
{
	return Vector3D(v1._x - v2._x, v1._y - v2._y, v1._z - v2._z);
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2)
{
	return Vector3D(v1._x + v2._x, v1._y + v2._y, v1._z + v2._z);
}

Vector3D operator*(const Vector3D& v1, const Vector3D& v2)
{
	return Vector3D(v1._x * v2._x, v1._y * v2._y, v1._z * v2._z);
}

Vector3D operator*(double factor, const Vector3D& v1)
{
	return v1 * factor;
}


Vector3D operator/(const Vector3D& v1, const Vector3D& v2)
{
	return Vector3D(v1._x / v2._x, v1._y / v2._y, v1._z / v2._z);
}




Vector3D operator*(const Vector3D& v1, double factor)
{
	Vector3D returnValue;
	returnValue._x = v1._x * factor;
	returnValue._y = v1._y * factor;
	returnValue._z = v1._z * factor;
	return returnValue;
}

Vector3D operator/(const Vector3D& v1, double factor)
{
	Vector3D returnValue;
	returnValue._x = v1._x / factor;
	returnValue._y = v1._y / factor;
	returnValue._z = v1._z / factor;
	return returnValue;
}


Vector3D& Vector3D::operator=(const Vector3D& v1)
{
	_x = v1._x;
	_y = v1._y;
	_z = v1._z;

	return *this;
}


std::ostream& operator<<(std::ostream& os, const Vector3D& p)
{
	os << "("<< p._x << ", " << p._y << ", " << p._z << ")";
	return os;
}
