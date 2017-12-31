#include "pixel.hpp"
#include <iostream>
#include <cmath>



Pixel::Pixel(const Point3D& p, const Color& c):_color(c), _position(p){}

Color Pixel::computeColor(const Light& light, Shape* shape, Point3D intersection, int stoppingCriterion, std::vector<std::unique_ptr<Shape>>& shapes, Ray incidentRay, int k, int l)
{
  if(stoppingCriterion < 0)
  {
    return Color(0,0,0);
  }

  Ray* normalRay = Ray::createRay(shape->getCenter(), intersection);
  Ray* lightRay = Ray::createRay(intersection, light.getPosition());
  double alpha = normalRay->getAngle(*lightRay);
  double cosAlpha = cos(alpha);
  if(cosAlpha < 0)
  {
    cosAlpha = - cosAlpha;
  }
  normalRay->getDirection().normalize();
  Vector3D* normal = Vector3D::createVector(shape->getCenter(), intersection);
  normal->normalize();
  Vector3D mLight(light.getPosition().getX(), light.getPosition().getY(), light.getPosition().getZ());
  Vector3D interPoint(intersection.getX(), intersection.getY(), intersection.getZ());
  Ray refRay(incidentRay.reflectedRay(intersection, *normal));
  Vector3D interToLight(mLight - interPoint);
  interToLight.normalize();
  //std::cout << "refRay" << refRay << std::endl;
  int i = 0;
  int t = -1;
  std::vector<double> solutions;
  std::vector<int> iDs;
  for(auto& shapeiT : shapes )
  {
    t = (*shapeiT).intersectionWithRay(refRay);
    if(t >= 0)
    {
      // std::cout << "t : " << t << std::endl;
      // std::cout << "_shapeID : " << i << "\n" << std::endl;
      solutions.push_back(t);
      iDs.push_back(i);
    }
    i++;
  }
  if(! solutions.empty())
  {
    double bestSolution = solutions.at(0);
    int bestID = iDs.at(0);

    for(size_t j = 1; j < solutions.size(); j++)
    {
      if(solutions.at(j) < bestSolution)
      {
        bestSolution = solutions.at(j);
        bestID = iDs.at(j);
      }
    }


    Color Cr(computeColor(light,shapes.at(bestID).get(),*normalRay->computeIntersection(bestSolution),stoppingCriterion-1, shapes, refRay,k,l));
    Color newColor((1 - shape->getReflection()) * cosAlpha * light.getColor() * shape->getColor() / 255 + shape->getReflection() * Cr);
    _color = newColor;
    if(k == 130 && l == 247)
    {
      std::cout << "(1 - shape->getReflection()) : " << (1 - shape->getReflection()) << std::endl;
      std::cout << "stoppingCriterion : " << stoppingCriterion << std::endl;
      std::cout << "cos(alpha) : " << cosAlpha << std::endl;
      std::cout << "normal->scalarProduct(interToLight) : " << normal->scalarProduct(interToLight) << std::endl;
      std::cout << "light.getColor() : " << light.getColor() << std::endl;
      std::cout << "shape->getColor() : " << shape->getColor() << std::endl;
      std::cout << "(1 - shape->getReflection()) * cos(alpha) * light.getColor() * shape->getColor() / 255 : " << (1 - shape->getReflection()) * cosAlpha * light.getColor() * shape->getColor() / 255 << std::endl;
      std::cout << "Cr : " << Cr << std::endl;
    }
    delete(normalRay);
    delete(lightRay);
    return newColor;
  }


  delete(normalRay);
  delete(lightRay);
  //std::cout << cos(alpha) * light.getColor() * shape->getColor() / 255 << std::endl;
  //setColor(cosAlpha * light.getColor() * shape->getColor() / 255. );
  setColor((1 - shape->getReflection()) * cosAlpha * light.getColor() * shape->getColor() / 255);
  return Color((1 - shape->getReflection()) * cosAlpha * light.getColor() * shape->getColor() / 255);
  //return Color(cosAlpha * light.getColor() * shape->getColor() / 255. );

}

std::ostream& operator <<(std::ostream& os, const Pixel& pixel)
{
  os << pixel._color ;
  return os;
}
