#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "scene.hpp"
#include "screen.hpp"
#include "light.hpp"
#include "shape.hpp"
#include "camera.hpp"

using namespace std;

int main()
{
	Scene scene;

	scene.loadScene("./scenes/scene1.sc");
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
