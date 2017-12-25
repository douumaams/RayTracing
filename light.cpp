#include "light.hpp"

Light::Light(const Point3D& p, const Color& c):_position(p), _color(c)
{}

Light::Light(int x, int y, int z, int r, int g, int b):
	_position(x,y,z), _color(r,g,b)
{
	// _position = Point3D(x, y ,z);
	// _color = Color(r, g, b);
}
Light::~Light(){}