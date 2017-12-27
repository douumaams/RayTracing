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
	Point3D p1(2,2,2), p2(5,5,5);
	Vector3D v1(5,5,5);


	Point3D p3(p1+p2);
	p3 = p2;

	Ray ray(p1, v1);
	cout << p3 <<endl;

	// Scene scene;

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
