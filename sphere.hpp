#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "shape.hpp"
#define eps 1e-10

class Sphere : public Shape
{
	private:
	double _radius;

	public:
		Sphere() = default;
		Sphere(const Point3D& p, const Color& c, double reflection, double radius);
		virtual ~Sphere();

		virtual double intersectionWithRay(const Ray& ray); // redifinition de la methode dans shape

		double getRadius() const { return _radius; };
};

#endif
