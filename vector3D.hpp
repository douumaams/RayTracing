#ifndef __VECTOR3D_HPP__
#define __VECTOR3D_HPP__

#include <cmath>
#include <ostream>

class Vector3D
{
	private:
		double _x, _y, _z;
	public:
		Vector3D() = default;
		Vector3D(double x, double y, double z);
		Vector3D(const Vector3D& v);
		~Vector3D();
		// double getNorm(){ return sqrt(pow(_x,2) + pow(_y,2) + pow(_z,2));}
		double getX() const {return _x;};
		double getY() const {return _y;};
		double getZ() const {return _z;};

		double getNorm() const { return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));}
		double scalarProduct(const Vector3D& v);

		void normalize() { divide(getNorm()); };
		void multiply(const double factor) { _x *= factor; _y *= factor; _z *= factor;};
		void divide(const double factor) { _x /= factor; _y /= factor; _z /= factor;};

		friend bool operator==(const Vector3D& v1, const Vector3D& v2);
		friend bool operator!=(const Vector3D& v1, const Vector3D& v2);
		friend Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
		friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
		friend Vector3D operator/(const Vector3D& v1, const Vector3D& v2);
		friend Vector3D operator*(const Vector3D& v1, const Vector3D& v2);
		friend std::ostream& operator<<(std::ostream& os, const Vector3D& v);

		friend Vector3D operator/(const Vector3D& v1, double factor);
		friend Vector3D operator/(double factor, const Vector3D& v1);
		friend Vector3D operator*(const Vector3D& v1, double factor);
		friend Vector3D operator*(double factor, const Vector3D& v1);
		Vector3D& operator=(const Vector3D& v1);

};


#endif
