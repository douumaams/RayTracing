#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "screen.hpp"
#include "light.hpp"
#include "shape.hpp"
#include "camera.hpp"

#define CAMERA_POSITION 0
#define TOP_LEFT_CORNER 1
#define TOP_RIGHT_CORNER 2
#define BOTTOM_LEFT_CORNER 3
#define HORIZONTAL_RESOLUTION 4
#define BACKGROUND_COLOR 5
#define LIGHT_SOURCE_POSITION 6
#define SHAPES 7


class Scene
{
		

	private:
		Camera _camera;
		Light _light;
		std::vector<Shape> _shapes;

		//void parseLine();
		int error(std::string function, std::string msg);

	public:
		Scene(const std::string& scene_name);
		virtual ~Scene();
		int loadScene(const std::string& scene_name);
		int saveScene(const std::string& scene_name);
		Camera getCamera() const { return _camera; }
		Light getLight() const { return (_light); }
		// std::map<std::string, std::vector<double>> parseShape(std::string line);
		std::pair<std::string, std::vector<double>> parseShape(std::string line);
		std::vector<double> parseInt(std::string line);

};


#endif