#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "shape.hpp"

class Sphere : public Shape
{
	public:
		Sphere() = default;
		Sphere(const Point3D& p, const Color& c, double reflection, double radius);
		virtual ~Sphere();
		double getRadius() const { return _radius; }
		virtual double intersectionWithRay(const Ray& ray);
	private:
		double _radius;

};

#endif
