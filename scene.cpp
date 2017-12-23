#include "scene.hpp"
#include <iostream>
#include <fstream>
#include <string.h>


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

			if(line_number < 7)
			{
				std::vector<double> v = parseInt(line);
				for (std::vector<double>::iterator i = v.begin(); i != v.end(); ++i)
				{
					std::cout << *(i) << std::endl;
				}
					std::cout << line << std::endl;
			}else
			{
				std::map<std::string, std::vector<double>> m = parseShape(line);


				for (std::map<std::string, std::vector<double>>::iterator it = m.begin(); it != m.end(); ++it)
				{
 					std::cout << it->first << " => ";
 					for (std::vector<double>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
 					{
 						std::cout << *(it2) << "-";
 					}
 					std::cout << std::endl;
				}
			}

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
		return_value.push_back(std::stol(line.substr(0, str)));
		line = line.substr(str + 1);
	}
	return return_value;
}

std::map<std::string, std::vector<double>> Scene::parseShape(std::string line) /*(La clé :contient le type de la forme, La valeur contient les informations)*/
{
	std::map<std::string, std::vector<double>> return_value;
	std::string::size_type str = line.find(':');
	return_value[line.substr(0, str)] = parseInt(line.substr(str + 1));
	return return_value;
}


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
