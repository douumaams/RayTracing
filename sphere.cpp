#include "sphere.hpp"


Sphere::Sphere(const Point3D& p, const Color& c, int reflection, int radius):Shape(p, c, reflection), _radius(radius)
{

}

Sphere::~Sphere(){}

int Sphere::getRadius()
{
  return _radius;
}
