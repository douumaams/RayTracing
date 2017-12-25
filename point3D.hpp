#ifndef __POINT3D_HPP__
#define __POINT3D_HPP__

#include <cmath>
#include <ostream>
class Point3D
{	
	private:
		int _x, _y, _z;
	public:
		Point3D(Point3D const& p);
		Point3D(int xx, int yy, int zz);
		~Point3D();
		double getNorm() const { return sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2)); }

	friend Point3D operator-(const Point3D& p1, const Point3D& p2);
	friend Point3D operator+(const Point3D& p1, const Point3D& p2);
	friend std::ostream& operator<<(std::ostream& os, const Point3D& p);
};




#endif