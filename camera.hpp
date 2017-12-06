#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "util.hpp"

class Camera
{
	public:
		Camera(int x = 0, int y = 0, int z = 0);
		virtual ~Camera();
	private:
		Position _position;
};



#endif