#ifndef __RAY_HPP__
#define __RAY_HPP__

#include "point3D.hpp"
#include "vector3D.hpp"

#include <ostream>
#include <vector>

class Ray
{
  private:
    Point3D _origin;
    Vector3D _direction;

  public:
    Ray() = default;
    Ray(const Point3D& origin, const Vector3D& direction);
    ~Ray();

    static Ray* createRay(const Point3D& origin, const Point3D& arrival); // cree un rayon entre deux points

    double getAngle(const Ray& r); // calcul l'angle entre ce vecteur et r
    const Point3D* computeIntersection(const double t); // calcul le point a l'emplacement t
    Ray reflectedRay(const Point3D& origin, const Vector3D& normal); // calcul le rayon reflechi

    Vector3D getDirection() const {return _direction;};
    Point3D getOrigin() const {return _origin;};

    friend std::ostream& operator<<(std::ostream& os, const Ray& ray);
};

#endif
