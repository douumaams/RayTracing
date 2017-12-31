#include "pixel.hpp"
#include <iostream>
#include <cmath>



Pixel::Pixel(const Point3D& p, const Color& c):_color(c), _position(p){}

std::ostream& operator <<(std::ostream& os, const Pixel& pixel)
{
  os << pixel._color ;
  return os;
}
