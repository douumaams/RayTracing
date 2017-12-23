#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "util.hpp"
#include "shape.hpp"

class Sphere : public Shape
{
	public:
		Sphere(int x, int y, int z, int r, int g, int b, int reflection, int radius);
		~Sphere();

	private:
		int _radius;
};

#endif
