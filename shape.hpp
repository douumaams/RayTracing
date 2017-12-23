#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include "position.hpp"
#include "color.hpp"

class Shape
{
	public:
		Shape(int x = 0, int y = 0, int z = 0, int r = 255, int g = 255, int b = 255, int reflection = 0.5);
		virtual ~Shape();

	private:
		Position _center;
		Color _color;
		double _reflection;

};

#endif
