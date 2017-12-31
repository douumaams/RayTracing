#include "sphere.hpp"
#include <iostream>

Sphere::Sphere(const Point3D& p, const Color& c, double reflection, double radius):
Shape(p, c, reflection), _radius(radius)
{}

Sphere::~Sphere(){}

// renvoi un nombre positif s'il y a une intersection et un nombre negatif sinon
double Sphere::intersectionWithRay(const Ray& ray)
{
  Vector3D rayDirection(ray.getDirection());
  Point3D rayOrigin(ray.getOrigin());

  // On definit le polynome a resoudre
  double a = pow(rayDirection.getX(), 2) + pow(rayDirection.getY(), 2) + pow(rayDirection.getZ(), 2);
  double b = 2 * ( rayDirection.getX()*(rayOrigin.getX() - getCenter().getX()) + rayDirection.getY()*(rayOrigin.getY() - getCenter().getY()) + rayDirection.getZ()*(rayOrigin.getZ() - getCenter().getZ()));
  double c = pow((rayOrigin.getX() - getCenter().getX()), 2) + pow((rayOrigin.getY() - getCenter().getY()), 2) + pow((rayOrigin.getZ() - getCenter().getZ()), 2) - getRadius();

  double discriminant = pow(b, 2) - (4 * a * c);

  if(discriminant < 0.0) // pas de solutions
  {
    return -1.0;
  }
  else
  {
    double solution1 = ( - b - sqrt(discriminant) ) / 2 / a - eps;
    double solution2 = ( - b + sqrt(discriminant) ) / 2 / a - eps;

    if(solution1 >= 0.0) // t >= 0
    {
      return solution1;
    }
    else
    {
      if(solution2 >= 0.0) // t >= 0
      {
        return solution2;
      }
      else // si t < 0 alors l'intersection se situe derriere le point d'origine du rayon donc il n'a a pas d'intersection
      {
        return -1.0;
      }
    }
  }
}
