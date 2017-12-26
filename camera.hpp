#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "point3D.hpp"

class Camera
{
	private:
		Point3D _position;

	public:
		// faut voir question double---->int
		Camera(int x , int y, int z);
		// Camera(const Point3D& p);
		virtual ~Camera();

};



#endif
