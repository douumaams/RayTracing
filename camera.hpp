#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "point3D.hpp"
#include "screen.hpp"
#include <ostream>

class Camera
{
	private:
		Point3D _position;
		Screen _screen;
	public:
		Camera() = default;
		Camera(Point3D position, Point3D top_left, Point3D top_right, Point3D bottom_left, int horizontal_res, Color background);
		virtual ~Camera();

	  friend std::ostream& operator <<(std::ostream& os, const Camera& camera);
		Point3D getPosition() const {return _position;};
		Screen getScreen() const { return _screen;};

};



#endif
