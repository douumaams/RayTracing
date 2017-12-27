#ifndef __RAY_HPP__
#define __RAY_HPP__

#include "point3D.hpp"
#include "vector3D.hpp"
#include "light.hpp"
#include "sphere.hpp"

// ray definit par un point d'origine (position 3D) et une direction (vecteur 3D)
class Ray
{
  private:
    Point3D _origin;
    Vector3D _direction;
    int _shapeID; // id de la sphere qui intersecte le rayon et -1 sinon

  public:

    Ray(const Point3D& origin, const Vector3D& direction);
    ~Ray();

    /*double discriminant(const Sphere& sphere);
    double solveEquation(const Sphere& sphere, double discriminant);*/

    // renvoie le point d'intersection ou -1 sinon
    friend double intersectionWithSphere(const Sphere& sphere);
    bool intersectionWithSource(const Light& source);

    friend static Ray createRay(const Point3D& origin, const Point3D& arrival);
    //Ray createRayFromCamera(const Point3D& cameraPos, const Pixel& pixel);
    Ray getTangent(const Sphere& sphere, const Point3D& intersection);
    Ray getPerpendicular(const Sphere& sphere, const Ray& tangent);
    //Ray createRayFromIntersection(const Point3D& source);

    double getAngle(const Ray& tangent, const Ray& perpendicular);
};

#endif

/*
- fonction qui renvoie la position 3D du pixel en fonction de sa position 2D "Position getPosition(int x, int y)"
- pour chaque pixel tracer un rayon issue de la camera: Ray drawRayFromCamera(Position pixelPos)
si intersectionWithSphere
  tracer un rayon issue du point d'intersection Ray drawRayFromIntersection(Position sourcePos)
  si intersectionWithSource
    pixel non eclaire (noir ?)
  sinon
    pixel eclaire
sinon
  couleur background


Ray createRayFromCamera(const Pixel& pixel)
creer un rayon issue de la cam allant vers le pixel

boolean intersectionWithSphere(Sphere s)
renvoie true si le rayon intersecte la Sphere

boolean intersectionWithSource(Source s)
renvoie true si le rayon intersecte la source)

Ray getTangent(Sphere s, Position intersection)
renvoie la tangente de la sphere au point d'intersection

getPerpendicular(Sphere s, Ray tangent)
renvoie la perpendiculaire à la tangente

int getAlpha(Ray tangent, Ray perpendicular)
revoie l'angle entre la perpendiculaire à la tangente et le rayon vers la source

Ray drawRayFromIntersection(Position source)
renvoie le rayon entre issue du point d'intersection allant vers la source
*/

/* Scene
pour chaque pixel de l'ecran calculer sa couleur et l'écrire dans le fichier ppm
*/
