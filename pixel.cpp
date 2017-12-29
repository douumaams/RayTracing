#include "pixel.hpp"
#include <iostream>
#include <cmath>


Pixel::Pixel(const Point3D& p, const Color& c):_color(c), _position(p){}

void Pixel::computeColor(const Light& light, Shape* shape, Point3D intersection)
{
  // 1. intersectionWithSphere (calcul du point d'intersection)
  // 2. intersectionWithSource
  // 3. recupere l'angle alpha
  // 4. fait le calcul du pixel

  Ray* intersectionRay = Ray::createRay(shape->getCenter(), intersection);
  Ray* lightRay = Ray::createRay(intersection, light.getPosition());

  double alpha = intersectionRay->getAngle(*lightRay);
  Color newColor(cos(alpha) * light.getColor() * shape->getColor() / 255);
  _color = newColor;
  std::cout << "Couleur : " << _color << std::endl;
}
