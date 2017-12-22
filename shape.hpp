#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include "util.hpp"

class Shape
{
	public:
		Shape(int x = 0, int y = 0, int z = 0);
		virtual ~Shape();

	private:
		Position _center;
		Color _color;
		double _reflection;

};

#endif