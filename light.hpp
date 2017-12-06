#ifndef __LIGHT_H__
#define __LIGHT_H__


#include "util.hpp"

class Light
{
	public:
		Light(int x, int y, int z);
		~Light();

	private:
		Position _position;
};

#endif