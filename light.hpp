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
		Light() = default;
		Light(const Point3D& p, const Color& c);
		~Light();

		Point3D getPosition() const { return _position;};
		Color getColor() const { return _color;};

};

#endif
