#include "sphere.hpp"


Sphere::Sphere(const Point3D& p, const Color& c, double reflection, double radius):Shape(p, c, reflection), _radius(radius)
{

}

Sphere::~Sphere(){}

/*const Point3D& getCenter()
{
  return _center;
}

const int getRadius()
{
  return _radius;
}*/
