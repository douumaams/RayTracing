#include "scene.hpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include "point3D.hpp"
#include "color.hpp"

Scene::Scene(){}

Scene::~Scene(){}


int Scene::error(std::string function, std::string msg)
{
	std::cerr << function <<":"<< msg << std::endl;
	return -1;
}

int Scene::loadScene(std::string scene_name)
{
	// if(scene_name == NULL)
	// 	return error("[Scene::load_scene]","file null");

	std::ifstream reader;
	reader.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	int line_number = 0;
	try
	{
		// Position top_left_corner, top_right_corner, bottom_left_corner;
		// Color background_color;

		std::string line;
		reader.open(scene_name.c_str());
		// while(!reader.eof())
		while(!getline(reader,line,'\n').eof())
		{

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
				case 0:
						// Camera Position
						std::cout << v.at(0) << " | " << v.at(1) << " | "<< v.at(2); // camera

						break;
				case 1:
						// std::vector<double> v = parseInt(line);
						// top left corner
						std::cout << "top_left_corner :" << v.at(0) << " | " << v.at(1) << " | "<< v.at(2);
						break;
				case 2:
						// std::vector<double> v = parseInt(line);
						// top right corner
						std::cout << "top_right_corner :" << v.at(0) << " | " << v.at(1) << " | "<< v.at(2);
						break;
				case 3:
						// std::vector<double> v = parseInt(line);
						// bottom left corner
						std::cout << "bottom_left_corner :" << v.at(0) << " | " << v.at(1) << " | "<< v.at(2);
						break;
				case 4:
						// std::vector<double> v = parseInt(line);
						// La resolution de l'ecran
						std::cout << "la resolution : "<< v.at(0) ; // camera
						break;
				case 5:
						// std::vector<double> v = parseInt(line);
						// La couleur du fond (background)
						std::cout << "background :" << v.at(0) << " | " << v.at(1) << " | "<< v.at(2);
						break;
				case 6:
						// std::vector<double> v = parseInt(line);
						// la lumiere
						std::cout << "la lumiere :" << v.at(0) << " | " << v.at(1) << " | "<< v.at(2) << " | " << v.at(3) << " | "<< v.at(4) << " | " << v.at(5) ;
									// line_number ++;

						break;
				default:
						std::pair<std::string, std::vector<double>> shape = parseShape(line);
						if(std::get<0>(shape) == "sphere")
						{
							std::cout << "sphere ";
							std::vector<double> vi = std::get<1>(shape);
							std::cout << vi.at(0);
							std::cout << " | ";
							std::cout << vi.at(1);
							std::cout << " | ";
							std::cout << vi.at(2);
							std::cout << " | ";
							std::cout << vi.at(3);
							std::cout << " | ";
							std::cout << vi.at(4);
							std::cout << " | ";
							std::cout << vi.at(5);
							std::cout << " | ";
							std::cout << vi.at(6);
							std::cout << " | ";
							std::cout << vi.at(7);
						}

						// la creation ds diffrentes forme
						// std::map<std::string, std::vector<double>> m = parseShape(line);
						// for (std::map<std::string, std::vector<double>>::iterator it = m.begin(); it != m.end(); ++it)
						// {
		 			// 		std::cout << it->first << " => ";
		 			// 		for (std::vector<double>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
		 			// 		{
		 			// 			std::cout << *(it2) << "-";
		 			// 		}
		 			// 		std::cout << std::endl;
						// }
			}
			std::cout << std::endl;
			// if(line_number < 7)
			// {


				// for (std::vector<double>::iterator i = v.begin(); i != v.end(); ++i)
				// {
				// 	std::cout << *(i) << std::endl;
				// }
				// 	std::cout << line << std::endl;
			// }else
			// {
				// std::map<std::string, std::vector<double>> m = parseShape(line);
				// for (std::map<std::string, std::vector<double>>::iterator it = m.begin(); it != m.end(); ++it)
				// {
 			// 		std::cout << it->first << " => ";
 			// 		for (std::vector<double>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
 			// 		{
 			// 			std::cout << *(it2) << "-";
 			// 		}
 			// 		std::cout << std::endl;
				// }
			// }

			line_number ++;

		}// avoir pourquoi il ne lit pas la derniere ligne
		reader.close();

	}catch(std::ifstream::failure &e)
	{
		// perror(errno);
		// std::cout << strerror(errno)<< std::endl;
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

// std::map<std::string, std::vector<double>> Scene::parseShape(std::string line) /*(La clé :contient le type de la forme, La valeur contient les informations)*/
// {
// 	std::map<std::string, std::vector<double>> return_value;
// 	std::string::size_type str = line.find(':');
// 	return_value[line.substr(0, str)] = parseInt(line.substr(str + 1));
// 	return return_value;
// }


// std::vector<int> Scene::parseInt(std::string line)
// {
// 	std::vector<int> return_value;
// 	std::string::size_type str = line.find(' ');
// 	// il faut traiter les exceptions (invalid_argument & out_of_range)
// 	while(str <= std::string::npos)
// 	{
// 		return_value.push_back(std::stoi(line.substr(0, str), &str));
// 		line = line.substr(str + 1);
// 		str = line.find(' ');
// 	}

// 	return return_value;
// }
