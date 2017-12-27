#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include "point3D.hpp"
#include "color.hpp"

class Shape
{
	public:
		Shape(const Point3D& p, const Color& c, const double reflection);
		virtual ~Shape();
		Point3D getCenter() const { return _center; }
		Color getColor() const { return _color; }
		double getReflection() const { return _reflection; }
	private:
		Point3D _center;
		Color _color;
		double _reflection;

};

#endif
