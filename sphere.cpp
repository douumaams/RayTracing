#include "sphere.hpp"
#include <iostream>


Sphere::Sphere(const Point3D& p, const Color& c, double reflection, double radius):
Shape(p, c, reflection), _radius(radius)
{}

Sphere::~Sphere(){}


double  Sphere::intersectionWithRay(const Ray& ray)
{
  Vector3D rayDirection(ray.getDirection());
  Point3D rayOrigin(ray.getOrigin());

  double a = pow(rayDirection.getX(), 2) + pow(rayDirection.getY(), 2) + pow(rayDirection.getZ(), 2);
  double b = 2 * ( rayDirection.getX()*(rayOrigin.getX() - getCenter().getX()) + rayDirection.getY()*(rayOrigin.getY() - getCenter().getY()) + rayDirection.getZ()*(rayOrigin.getZ() - getCenter().getZ()));
  double c = pow((rayOrigin.getX() - getCenter().getX()), 2) + pow((rayOrigin.getY() - getCenter().getY()), 2) + pow((rayOrigin.getZ() - getCenter().getZ()), 2) - pow(getRadius(), 2);

  double discriminant = pow(b, 2) - (4 * a * c);

  if(discriminant < 0.0)
  {
    // std::cout << "false" << std::endl;
    // std::cout << "discriminant < 0.0" << std::endl;
    return -1.0;
  }
  else
  {
    double solution1 = ( - b - sqrt(discriminant) ) / (2 * a);
    double solution2 = ( - b + sqrt(discriminant) ) / (2 * a);
    // std::cout << "solution1 = " << solution1 << std::endl;
    // std::cout << "solution2 = " << solution2 << std::endl;

    if(solution1 >= 0.0) // t >= 0
    {
      // std::cout << "true" << std::endl;
      // std::cout << "solution1 >= 0.0" << std::endl;
      return solution1;
    }
    else
    {
      if(solution2 >= 0.0) // t >= 0
      {
        // std::cout << "true" << std::endl;
        // std::cout << "solution2 >= 0.0" << std::endl;
        return solution2;
      }
      else
      {
        // std::cout << "false" << std::endl;
        // std::cout << "solution1 <= 0.0 && solution2 <= 0.0" << std::endl;
        return -1.0;
      }
    }

  }

}
