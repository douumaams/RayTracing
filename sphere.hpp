#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "util.hpp"

class Sphere
{
	public:
		Light(int x, int y, int z, int r, int g, int b);
		~Light();

	private:
		int _radius;
};

#endif