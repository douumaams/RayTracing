#include "scene.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "point3D.hpp"
#include "color.hpp"
#include "sphere.hpp"
#include "pixel.hpp"

Scene::Scene(const std::string& scene_name)
{
	loadScene(scene_name);
}

Scene::~Scene(){}


int Scene::error(std::string function, std::string msg)
{
	std::cerr << function <<":"<< msg << std::endl;
	return -1;
}

int Scene::loadScene(const std::string& scene_name)
{
	std::ifstream reader;
	reader.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	int line_number = 0;
	try
	{
		int horizontal_resolution;
		Point3D camera_position ,top_left_corner, top_right_corner, bottom_left_corner;
		Color background_color;

		std::string line;
		reader.open(scene_name.c_str());
		while(!reader.eof())
		{
			getline(reader,line,'\n');

			if(line.empty())
				continue;

			while(line.front() == ' ')
				line.pop_back();

			if(line.empty() || line.front() == '#')
				continue;

			std::vector<double> v;
			if(line_number < 7)
				v = parseInt(line);

			switch(line_number)
			{
				case CAMERA_POSITION:
						camera_position = Point3D(v.at(0), v.at(1), v.at(2));
						break;
				case TOP_LEFT_CORNER:
						top_left_corner = Point3D(v.at(0), v.at(1), v.at(2));
						break;
				case TOP_RIGHT_CORNER:
						top_right_corner = Point3D(v.at(0), v.at(1), v.at(2));
						break;
				case BOTTOM_LEFT_CORNER:
						bottom_left_corner = Point3D(v.at(0), v.at(1), v.at(2));
						break;
				case HORIZONTAL_RESOLUTION:
						horizontal_resolution = v.at(0);
						break;
				case BACKGROUND_COLOR:
						background_color = Color(v.at(0), v.at(1), v.at(2));
						_camera = Camera(camera_position, top_left_corner, top_right_corner, bottom_left_corner, horizontal_resolution, background_color);
						break;
				case LIGHT_SOURCE_POSITION:
						_light = Light(Point3D(v.at(0), v.at(1), v.at(2)),
										 Color(v.at(3), v.at(4), v.at(5))
									);
						break;
				default:
						std::pair<std::string, std::vector<double>> shape = parseShape(line);
						v = std::get<1>(shape);
						if(std::get<0>(shape) == "sphere")
						{
							_shapes.push_back(std::unique_ptr<Shape>(new Sphere(Point3D(v.at(0), v.at(1), v.at(2)),
													Color(v.at(4), v.at(5), v.at(6)),
													v.at(7),
													v.at(3)
												)));
						}
			}
			line_number ++;

		}

		reader.close();
	}catch(std::ifstream::failure &e)
	{
		if(reader.eof() != 1) // parce que getline lance une exception lors de la fin du fichier
		{
			std::cout << e.what() << std::endl;
			return error("[Scene::load_scene]","opening/reading/closing file");
		}
	}

	return 0;
}


std::vector<double> Scene::parseInt(std::string line)
{
	std::vector<double> return_value;
	std::string::size_type str;
	// il faut traiter les exceptions (invalid_argument & out_of_range)
	while(line.back() == ' ') // on enleve tous les espace qui se situe a la fin de note string
		line.pop_back();

	while(str != std::string::npos)
	{
		while(line.front() == ' ')
			line = line.substr(1);
		str = line.find(' ');
		return_value.push_back(std::stod(line.substr(0, str)));
		line = line.substr(str + 1);
	}
	return return_value;
}

std::pair<std::string, std::vector<double>> Scene::parseShape(std::string line)
{
	std::string::size_type str = line.find(':');
	return make_pair(line.substr(0, str), parseInt(line.substr(str + 1)));
}

void Scene::saveScene(const std::string& scene_name)
{
    std::ofstream os(scene_name);

    os << "P3" << std::endl;
    os << _camera;
}

std::pair<double, int> Scene::findNearestIntersection(const Ray& ray)
{
	double t = -1;
	int i = 0;
	std::vector<double> intersections;
	std::vector<int> shapeIDs;

	for(auto& shapeiT : _shapes )
	{
		t = (*shapeiT).intersectionWithRay(ray);
		if(t >= 0)
		{
			intersections.push_back(t);
			shapeIDs.push_back(i);
		}
		i++;
	}

	if(intersections.empty())
	{
		return std::make_pair(-1, -1);
	}

	double bestSolution = intersections.at(0);
	int bestID = shapeIDs.at(0);

	for(size_t j = 1; j < intersections.size(); j++)
	{
		if(intersections.at(j) < bestSolution)
		{
			bestSolution = intersections.at(j);
			bestID = shapeIDs.at(j);
		}
	}

	return std::make_pair(bestSolution, bestID);

}

Color Scene::computeColor(int x, int y, int stoppingCriterion, Shape* shape, Ray incidentRay, Point3D intersection)
{
	if(stoppingCriterion < 0)
  {
    return Color(0,0,0);
  }

  Ray* normalRay = Ray::createRay(shape->getCenter(), intersection);
  Ray* lightRay = Ray::createRay(intersection, _light.getPosition());
  double cosAlpha = cos(normalRay->getAngle(*lightRay));
	std::pair<double, int> result;
	double bestSolution;
	int bestID;

	if(cosAlpha < 0)
	{
		cosAlpha = - cosAlpha;
	}

  normalRay->getDirection().normalize();
  Vector3D* normal = Vector3D::createVector(shape->getCenter(), intersection);
  normal->normalize();

  Ray refRay(incidentRay.reflectedRay(intersection, *normal));


	result = findNearestIntersection(refRay);
	bestSolution = std::get<0>(result);
	bestID = std::get<1>(result);

	if(bestSolution >= 0)
	{
		Color Cr(computeColor(x,y, stoppingCriterion-1, _shapes.at(bestID).get(), refRay, *normalRay->computeIntersection(bestSolution)));
    Color newColor((1 - shape->getReflection()) * cosAlpha * _light.getColor() * shape->getColor() / 255 + shape->getReflection() * Cr);
    getPixel(x,y).setColor(newColor);

    delete(normalRay);
    delete(lightRay);
    return newColor;
	}

  delete(normalRay);
  delete(lightRay);

  getPixel(x,y).setColor((1 - shape->getReflection()) * cosAlpha * _light.getColor() * shape->getColor() / 255);
  return Color((1 - shape->getReflection()) * cosAlpha * _light.getColor() * shape->getColor() / 255);
}

void Scene::rendering()
{
	/*
	1. pour chaque pixel de l'écran creer un rayon issue de la camera
	2. parcourir chaque sphere et verifier s'il y a une intersection (garder la sphere la plus proche)
	3a. s'il n'y a pas d'intersection le pixel est de la couleur du background
	3.b sinon creer un rayon entre le point d'intersection et la source
	4. verifier l'intersection avec la source de lumière
	5.a si pas intersectionWithSource calcul de alpha et de la couleur du pixel
	5.b sinon pixel de couleur noir
	*/

	Ray* cameraRay;
	Ray* lightRay;
	std::pair<double, int> result;
	double bestSolution2;
	int bestID2;

	// on parcours chaque pixel
	for (int k = 0; k < _camera.getScreen().getVerticalResolution(); k++)
	{
		for (int l = 0; l < _camera.getScreen().getHorizontalResultion(); l++)
		{
				cameraRay = Ray::createRay(_camera.getPosition(), getPixel(k,l).getPosition());

				result = findNearestIntersection(*cameraRay);
				bestSolution2 = std::get<0>(result);
				bestID2 = std::get<1>(result);

				if(bestSolution2 < 0) // il n'y a pas d'intersections
				{
					// on ne fait rien car les pixels sont initialies a la couleur du background
				}
				else
				{
					const Point3D* pointIntersection(cameraRay->computeIntersection(bestSolution2));

					lightRay = Ray::createRay(*pointIntersection, _light.getPosition());

					result = findNearestIntersection(*lightRay); // on teste l'intersection avec la source
					bestSolution2 = std::get<0>(result);

					if(bestSolution2 >= 0)
					{
						// il y a un obstacle entre la source et le point d'intersection donc le pixel est noir
						getPixel(k,l).setColor(Color(0,0,0));
					}
					else
					{
						computeColor(k,l,1,_shapes.at(bestID2).get(), *cameraRay, *pointIntersection);
					}
				}
		}

	}
}
