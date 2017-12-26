#ifndef __VECTOR3D_HPP__
#define __VECTOR3D_HPP__

#include <cmath>

class Vector3D
{
	private:
		double _x, _y, _z;
	public: 
		Vector3D(double x, double y, double z):_x(x), _y(y), _z(z){};
		~Vector3D(){}
		// double getNorm(){ return sqrt(pow(_x,2) + pow(_y,2) + pow(_z,2));}
		
};

#endif