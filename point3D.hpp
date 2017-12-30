#ifndef __POINT3D_HPP__
#define __POINT3D_HPP__

#include <cmath>
#include <ostream>

class Point3D
{
	private:
		double _x, _y, _z;
	public:
		Point3D() = default;
		Point3D(Point3D const& p);
		Point3D(double xx, double yy, double zz);
		~Point3D();
		double getNorm() const { return sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2)); }
		double getX() const {return _x;};
		double getY() const {return _y;};
		double getZ() const {return _z;};

		friend Point3D operator-(const Point3D& v1, const Point3D& v2);
		friend Point3D operator+(const Point3D& v1, const Point3D& v2);
		friend Point3D operator/(const Point3D& v1, const Point3D& v2);
		friend Point3D operator*(const Point3D& v1, const Point3D& v2);
		friend std::ostream& operator<<(std::ostream& os, const Point3D& v);

		friend Point3D operator/(const Point3D& v1, double factor);
		friend Point3D operator*(const Point3D& v1, double factor);
		friend Point3D operator/(double factor, const Point3D& v1);
		friend Point3D operator*(double factor, const Point3D& v1);
		Point3D& operator=(const Point3D& v1);
};

#endif
