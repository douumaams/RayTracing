#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "shape.hpp"

class Sphere : public Shape
{
	public:
		Sphere(const Point3D& p, const Color& c, double reflection, double radius);
		virtual ~Sphere();
		double getRadius() const { return _radius; }
	private:
		double _radius;

};

#endif
