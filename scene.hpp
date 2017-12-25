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

class Scene
{
	public:
		Scene();
		virtual ~Scene();
		int loadScene(std::string scene_name);
		Camera getCamera() const { return *(_camera); }
		Screen getScreen() const { return *(_screen); }
		Light getLight() const { return *(_light); }
		// std::map<std::string, std::vector<double>> parseShape(std::string line);
		std::pair<std::string, std::vector<double>> parseShape(std::string line);
		std::vector<double> parseInt(std::string line);


	private:
		Camera* _camera;
		Screen* _screen;
		Light* _light;
		std::vector<Shape*> _shapes;

		//void parseLine();
		int error(std::string function, std::string msg);

};


#endif