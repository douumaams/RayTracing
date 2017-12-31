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
#include <memory> // utile pour unique_ptr

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
		std::vector<std::unique_ptr<Shape>> _shapes;

		int error(std::string function, std::string msg);

	public:
		Scene(const std::string& scene_name);
		virtual ~Scene();
		int loadScene(const std::string& scene_name);
		void saveScene(const std::string& scene_name);

		void rendering();
		std::pair<std::string, std::vector<double>> parseShape(std::string line);
		std::vector<double> parseInt(std::string line);

		Color computeColor(int x, int y, int stoppingCriterion, Shape* shape, Ray incidentRay, Point3D intersection);

		std::pair<double, int> findNearestIntersection(const Ray& ray);

		Camera getCamera() const { return _camera; };
		Light getLight() const { return _light; };
		Pixel& getPixel(int x, int y) { return _camera.getPixel(x,y);};

};


#endif
