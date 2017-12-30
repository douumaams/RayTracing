#include "ray.hpp"
#include <cmath>
#include <iostream>

Ray::Ray(const Point3D& origin, const Vector3D& direction) :
_origin(origin), _direction(direction), _shapeID(-1)
{}

Ray::~Ray(){}

Ray* Ray::createRay(const Point3D& origin, const Point3D& arrival)
{
  double dx = arrival.getX() - origin.getX();

  double dy = arrival.getY() - origin.getY();

  double dz = arrival.getZ() - origin.getZ();

  Vector3D direction(dx, dy, dz);
  direction.normalize();

  return new Ray(origin, direction);
}

std::ostream& operator<<(std::ostream& os, const Ray& ray)
{
  os << "Origin : " << ray._origin << " Direction : " << ray._direction << std::endl;
  return os;
}

double Ray::getAngle(const Ray& r)
{
	//_direction.normalize();
	//r.getDirection().normalize();

  double alpha = acos(_direction.scalarProduct(r.getDirection()));
  //std::cout << "alpha : " << alpha << std::endl;
  return alpha;
}

const Point3D* Ray::computeIntersection(const double t)
{
  double x = _origin.getX() + t * _direction.getX();
  double y = _origin.getY() + t * _direction.getY();
  double z = _origin.getZ() + t * _direction.getZ();

  return new Point3D(x,y,z);
}
