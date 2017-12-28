#include "pixel.hpp"

Pixel::Pixel(const Point3D& p, const Color& c):_color(c), _position(p){}

/*void Pixel::computeColor(const Color& lightColor, const Color& shapeColor)
{
  1. intersectionWithSphere (calcul du point d'intersection)
  2. intersectionWithSource
  3. recupere l'angle alpha
  4. fait le calcul du pixel

}*/
