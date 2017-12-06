#include <cstdio>
#include <cstdlib>
#include "scene.hpp"
#include "screen.hpp"
#include "light.hpp"
#include "shape.hpp"
#include "camera.hpp"

int main()
{
	Scene scene;

	scene.load_scene("./scenes/scene1.sc");

	return 0;
}