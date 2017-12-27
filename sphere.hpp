#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "shape.hpp"

class Sphere : public Shape
{
	public:
	//	Sphere(int x, int y, int z, int r, int g, int b, int reflection, int radius);
		Sphere(const Point3D& p, const Color& c, int reflection, int radius);
		~Sphere();

		int getRadius();


	private:
		int _radius;
};

#endif
