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

using namespace std;

int main()
{
	Point3D p1(2,2,2), p2(5,5,15);
	Vector3D v1(3,3,0);
	Vector3D v2(-3,3,0);
	v1.multiply(10);
	cout << v1 << endl;
	v1.divide(10);
	cout << v1 << endl;

	Point3D p3(p1+p2);
	p3 = p2;


	Ray ray(p1, v1);
	Ray ray2(p2, v2);
	double radius = 10;
	double reflection = 1;
	Point3D center(100,100,100);
	Color color(255,255,255);
	Sphere sphere(center, color, reflection, radius);
	Ray* r = Ray::createRay(p1, p2);
	cout << *r;
	// double result = (*r).intersectionWithSphere(sphere);
	// cout << result << endl;

	ray.getAngle(ray2);
	//cout << p3 <<endl;

	//Scene scene("./scenes/scene1.sc");

	// scene.loadScene("./scenes/scene1.sc");
	// vector<int> values = scene.parseInt("     100         100   132   0  "); /// a revoir toute la fonction

	// for(vector<int>::iterator it = values.begin(); it !=values.end(); ++it)

 //    {
 //        cout << *it << endl;

 //    }


	return 0;
}

// // string::front
// #include <iostream>
// #include <string>

// int main ()
// {
//   std::string str ("test string");
//   str.front() = 'T';
//   std::cout << str.front() << '\n';
//   return 0;
// }
