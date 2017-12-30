#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "scene.hpp"
#include "screen.hpp"
#include "light.hpp"
#include "shape.hpp"
#include "camera.hpp"
#include "point3D.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "unityTesting.hpp"
#include "color.hpp"
using namespace std;

int main()
{
	// test createRay
	// Point3D p1(0,0,0);
	// Point3D p2(5,5,5);
	// Ray* r1 = Ray::createRay(p1, p2);
	// cout << *r1 << std::endl;
  //
	// Point3D p3(100,100,0);
	// Point3D p4(250,0,0);
	// Ray* r2 = Ray::createRay(p3, p4);
	// cout << *r2 << std::endl;
  //
	// Ray* r3 = Ray::createRay(p2, p1);
	// cout << *r3 << std::endl;

	Point3D sphereCenter(90,90,60);
	Color sphereColor(250,0,0);
	double sphereRadius = 7;
	double reflection = 0.3;

	Sphere sphere1(sphereCenter, sphereColor, sphereRadius, reflection);
	Scene scene("./scenes/scene1.sc");
	scene.rendering();
	scene.saveScene("./scenes/s.ppm");

	// Pixel pixel(sphereCenter, sphereColor);
	// std::cout << pixel << std::endl;
	// pixel.setColor(Color(0,0,0));
	// std::cout << pixel << std::endl;

	// Scene scene("./scenes/scene1.sc");
	// scene.rendering();
	// scene.saveScene("test.ppm");



	return 0;
}
