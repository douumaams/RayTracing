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
	// if(scene_name == NULL)
	// 	return error("[Scene::load_scene]","file null");

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


/*
*
*
*/
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

int Scene::saveScene(const std::string& scene_name) // pourquoi pas void ?? =)
{
    std::ofstream os(scene_name);

    os << "P3" << std::endl;
    os << _camera;

    // os.close();

	return 0;
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

	double t = -1;
	std::vector<double> solutions;
	std::vector<int> iDs;
	int i = 0;
	Ray* cameraRay;
	Ray* lightRay;

	std::vector<std::vector<Pixel>>& pixels = _camera.getScreen().getPixels();

	// on parcours chaque pixel
	for (int k = 0; k < _camera.getScreen().getVerticalResolution(); k++)
	{
		for (int l = 0; l < _camera.getScreen().getHorizontalResultion(); l++)
		{
				cameraRay = Ray::createRay(_camera.getPosition(), pixels[k][l].getPosition());
				i = 0;
				solutions.clear();
				iDs.clear();
				// pour chaque sphere on stocke l'intersection dans un vector et l'id de la sphere
				for(auto& shapeiT : _shapes )
				{
					t = (*shapeiT).intersectionWithRay(*cameraRay);
					if(t >= 0)
					{
						solutions.push_back(t);
						iDs.push_back(i);
					}
					i++;
				}

				// s'il n'y a pas d'intersection le vecteur est de la couleur du background
				if(solutions.empty())
				{
					// on ne fait rien car les pixels sont initialies a la couleur du background
				}
				else
				{
					// sinon on garde le point d'intersection et l'iD de la sphere la plus proche
					double bestSolution = solutions.at(0);
					int bestID = iDs.at(0);

					for(size_t j = 1; j < solutions.size(); j++)
					{
						if(solutions.at(j) < bestSolution)
						{
							bestSolution = solutions.at(j);
							bestID = iDs.at(j);
						}
					}

					const Point3D* pointIntersection(cameraRay->computeIntersection(bestSolution));
					// on teste l'intersection avec la source
					lightRay = Ray::createRay(*pointIntersection, _light.getPosition());
					i = 0;
					solutions.clear();
					iDs.clear();
					for(auto& shapeiT : _shapes )
					{
						t = (*shapeiT).intersectionWithRay(*lightRay);
						if(t >= 0)
						{
							solutions.push_back(t);
							iDs.push_back(i);
						}
						i++;
					}

					if(! solutions.empty())
					{
						// il y a un obstacle entre la source et le point d'intersection donc le pixel est noir
						_camera.getScreen().getPixels()[k][l].setColor(Color(0,0,0));
					}
					else
					{
						// il n'y a pas d'obstacles donc on calcule la couleur du pixel
						_camera.getScreen().getPixels()[k][l].computeColor(_light, _shapes.at(bestID).get(), *pointIntersection);
					}
				}
		}

	}


	//std::cout << _camera << std::endl;
}
