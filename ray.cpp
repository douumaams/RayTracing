#include "ray.hpp"
#include <cmath>
#include <iostream>

Ray::Ray(const Point3D& origin, const Vector3D& direction) :
_origin(origin), _direction(direction)
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

double Ray::getAngle(const Ray& r)
{
	r.getDirection().normalize();
  return acos(_direction.scalarProduct(r.getDirection()));
}

const Point3D* Ray::computeIntersection(const double t)
{
  double x = _origin.getX() + t * _direction.getX();
  double y = _origin.getY() + t * _direction.getY();
  double z = _origin.getZ() + t * _direction.getZ();

  return new Point3D(x,y,z);
}

Ray Ray::reflectedRay(const Point3D& origin, const Vector3D& normal)
{
  _direction.normalize();
  return Ray(origin, _direction - 2 * (_direction.scalarProduct(normal) * normal));
}

std::ostream& operator<<(std::ostream& os, const Ray& ray)
{
  os << "Origin : " << ray._origin << " Direction : " << ray._direction << std::endl;
  return os;
}
