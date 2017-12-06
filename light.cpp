#include "light.hpp"

Light::Light(int x, int y, int z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}
Light::~Light(){}