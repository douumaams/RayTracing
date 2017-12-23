#include "light.hpp"

Light::Light(int x, int y, int z, int r, int g, int b)
{
	_position = Position(x, y, z);
	_color = Color(r,g,b);
}
Light::~Light(){}
