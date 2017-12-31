#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include "point3D.hpp"
#include "color.hpp"
#include "ray.hpp"

class Shape
{
	private:
	Point3D _center;
	Color _color;
	double _reflection;

	public:
		Shape(const Point3D& p, const Color& c, const double reflection);
		virtual ~Shape();

		virtual double intersectionWithRay(const Ray& ray) = 0; // chaque sous classe redefinie la methode d'intersection

		Point3D getCenter() const { return _center; }
		Color getColor() const { return _color; }
		double getReflection() const { return _reflection; }

};

#endif
