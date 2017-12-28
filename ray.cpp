#include "ray.hpp"
#include <cmath>
#include <iostream>

Ray::Ray(const Point3D& origin, const Vector3D& direction) :
_origin(origin), _direction(direction), _shapeID(-1)
{}

Ray::~Ray(){}

Ray* Ray::createRay(const Point3D& origin, const Point3D& arrival)
{
  //std::cout << arrival.getX() << std::endl;
  //std::cout << origin.getX() << std::endl;
  double dx = arrival.getX() - origin.getX();
    //std::cout << dx << std::endl;
  double dy = arrival.getY() - origin.getY();
    //std::cout << dy << std::endl;
  double dz = arrival.getZ() - origin.getZ();
    //std::cout << dz << std::endl;
  Vector3D direction(dx, dy, dz);
  //Vector3D direction(arrival - origin);
  //std::cout << "x : " << direction.getX() << " y : " << direction.getY() << " z : " << direction.getZ() << std::endl;
  //Ray* ray = new Ray(origin, direction);
  return new Ray(origin, direction);
}

double Ray::intersectionWithSphere(const Sphere& sphere)
{
  const Point3D& center = sphere.getCenter();

  double a = pow(_direction.getX(), 2) + pow(_direction.getY(), 2) + pow(_direction.getZ(), 2);
  double b = 2 * ( _direction.getX()*(_origin.getX() - center.getX()) + _direction.getY()*(_origin.getY() - center.getY()) + _direction.getZ()*(_origin.getZ() - center.getZ()));
  double c = pow((_origin.getX() - center.getX()), 2) + pow((_origin.getY() - center.getY()), 2) + pow((_origin.getZ() - center.getZ()), 2) - pow(sphere.getRadius(), 2);

  double discriminant = pow(b, 2) - (4 * a * c);

  if(discriminant < 0.0)
  {
    std::cout << "false" << std::endl;
    std::cout << "discriminant < 0.0" << std::endl;
    return -1.0;
  }
  else
  {
    double solution1 = ( - b - sqrt(discriminant) ) / (2 * a);
    double solution2 = ( - b + sqrt(discriminant) ) / (2 * a);
    std::cout << "solution1 = " << solution1 << std::endl;
    std::cout << "solution2 = " << solution2 << std::endl;

    if(solution1 >= 0.0) // t >= 0
    {
      std::cout << "true" << std::endl;
      std::cout << "solution1 >= 0.0" << std::endl;
      return solution1;
    }
    else
    {
      if(solution2 >= 0.0) // t >= 0
      {
        std::cout << "true" << std::endl;
        std::cout << "solution2 >= 0.0" << std::endl;
        return solution2;
      }
      else
      {
        std::cout << "false" << std::endl;
        std::cout << "solution1 <= 0.0 && solution2 <= 0.0" << std::endl;
        return -1.0;
      }
    }

  }

  /*if(discriminant == 0.0)
  {
    double solution = - b / (2 * a);
    return true;
  }
  if(discriminant > 0.0)
  {
    double solution = ( - b - sqrt(discriminant) ) / (2 * a);
    return true;
  }*/

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
  std::cout << " alpha : " << alpha << std::endl;
  return alpha;
}

// bool Ray::intersectionWithSource(const std::vector<Sphere> spheres)
// {
//   for(Sphere s : spheres)
//   {
//     //if(s.intersectionWithRay(this) >= 0)
//       return true;
//   }
//
//   return false;
// }

const Point3D* Ray::computeIntersection(const double t)
{
  double x = _origin.getX() + t * _direction.getX();
  double y = _origin.getY() + t * _direction.getY();
  double z = _origin.getZ() + t * _direction.getZ();

  return new Point3D(x,y,z);
}
