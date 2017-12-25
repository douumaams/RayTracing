#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "point3D.hpp"
#include "color.hpp"


class Light
{
	private:
		Point3D _position;
		Color _color;
	public:
		Light(const Point3D& p, const Color& c);
		Light(int x, int y, int z, int r, int g, int b);
		~Light();

};

#endif