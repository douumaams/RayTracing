#include "light.hpp"

Light::Light(int x, int y, int z, int r, int g, int b)
	// _position.x(x); A voir
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_color.r = r;
	_color.g = g;
	_color.b = b;

}
Light::~Light(){}