#include "ray.hpp"
#include <cmath>

Ray::Ray(const Point3D& origin, const Vector3D& direction) : _origin(origin), _direction(direction), _shapeID(-1)
{}

Ray::~Ray(){}

Ray Ray::createRay(const Point3D& origin, const Point3D& arrival)
{
  Vector3D direction(arrival._x - origin._x, arrival._y - origin._y, arrival._z - origin._z);
  std::cout << "x : " << direction._x << "y : " << direction._y << "z : " << direction._z << std::endl;
  return Ray(origin, direction);
}

double Ray::intersectionWithSphere(const Sphere& sphere)
{
  Point3D center = sphere.getCenter();

  double a = pow(_direction._x, 2) + pow(_direction._y, 2) + pow(_direction._z, 2);
  double b = 2 * ( _direction._x*(_origin._x - center._x) + _direction._y*(_origin._y - center._y) + _direction._z*(_origin._z - center._z));
  double c = pow((_origin._x - center._x), 2) + pow((_origin._y - center._y), 2) + pow((_origin._z - center._z), 2) - pow(sphere.getRadius(), 2);

  double discriminant = pow(b, 2) -(4 * a * c);

  if(discriminant < 0.0)
  {
    return false;
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
      return solution1;
    }
    else
    {
      if(solution2 >= 0.0) // t >= 0
      {
        std::cout << "true" << std::endl;
        return solution2;
      }
      else
      {
        std::cout << "false" << std::endl;
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
