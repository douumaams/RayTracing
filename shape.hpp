#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include "point3D.hpp"
#include "color.hpp"

class Shape
{
	public:
		Shape(const Point3D& p,const Color& c);
		virtual ~Shape();

	private:
		Point3D _center;
		Color _color;
		double _reflection;

};

#endif
