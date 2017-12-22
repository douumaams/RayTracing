#ifndef __LIGHT_H__
#define __LIGHT_H__


#include "util.hpp"

class Light
{
	public:
		Light(int x, int y, int z, int r, int g, int b);
		~Light();

	private:
		Position _position;
		Color _color;
};

#endif