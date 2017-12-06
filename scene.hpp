#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>
#include <vector>
#include "screen.hpp"
#include "light.hpp"
#include "shape.hpp"
#include "camera.hpp"

class Scene
{
	public:
		Scene();
		virtual ~Scene();
		int load_scene(std::string scene_name);
		
		/* Je suis entrain de me demander si on peut faire une factory dans laquelle on va pouvoir parser le fichier et creer les instances */

		Camera getCamera() const& { return *(_camera); }
		Screen getScreen() const& { return *(_screen); }
		Light get_light() const& { return *(_light); }


	private:
		Camera* _camera;
		Screen* _screen;
		Light* _light;
		std::vector<Shape*> _shapes;

		//void parseLine();
		int error(std::string function, std::string msg);

};


#endif