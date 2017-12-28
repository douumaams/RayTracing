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
	normalize();
}

Vector3D::~Vector3D(){}



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

double Vector3D::scalarProduct(const Vector3D& v)
{
	return (this->_x * v.getX()) + (this->_y * v.getY()) + (this->_z * v.getZ());
}

/*Vector3D operator*(const Vector3D& v1, const double factor)
{

	v1._x = v1._x * factor;
	v1._y = v1._y * factor;
	v1._z = v1._z * factor;

	return v1;
}

Vector3D operator/(const Vector3D& v1, const double factor)
{
	Vector3D vector(v1);
	std::cout << vector._x << std::endl;
	vector._x = vector._x / factor;
	std::cout << vector._x << std::endl;
	vector._y = vector._y / factor;
	vector._z = vector._z / factor;

	return vector;
}*/

std::ostream& operator<<(std::ostream& os, const Vector3D& p)
{
	os << p._x << " " << p._y << " " << p._z;
	return os;
}
