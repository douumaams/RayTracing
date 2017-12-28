#ifndef __PIXEL_HPP__
#define __PIXEL_HPP__

#include "point3D.hpp"
#include "color.hpp"
// #include "ray.hpp"

class Pixel
{
private: // soit on met qu'un pixel est un point ou on fait une compostion a nous de choisir les deux methods sont bonnes
	Color _color;
	Point3D _position;
	/*Ray _raySphere;
	Ray _raySource;*/

public:
	Pixel(const Point3D& p, const Color& c);
	~Pixel(){};

	/* data */
	void computeColor(const Color& lightColor, const Color& shapeColor); // calcul la couleur du pixel
};

#endif
