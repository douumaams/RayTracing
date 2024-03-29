#ifndef __PIXEL_HPP__
#define __PIXEL_HPP__

#include "point3D.hpp"
#include "color.hpp"
#include "ray.hpp"
#include "light.hpp"
#include "sphere.hpp"
#include <memory>

class Pixel
{
	private:
	Color _color;
	Point3D _position;

	public:
	Pixel() = default;
	Pixel(const Point3D& p, const Color& c);
	~Pixel(){};

	Color getColor() const { return _color;};
	void setColor(const Color& color) { _color = color;};

	void setPosition(const Point3D& position) { _position = position;};
	Point3D getPosition() const {return _position;};

	friend std::ostream& operator <<(std::ostream& os, const Pixel& pixel);

};

#endif
