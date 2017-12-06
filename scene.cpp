#include "scene.hpp"
#include <iostream>
#include <fstream>

Scene::Scene(){}

Scene::~Scene(){}


int Scene::error(std::string function, std::string msg)
{
	std::cerr << function <<":"<< msg << std::endl;
	return -1;
}

int Scene::load_scene(std::string scene_name)
{
	// if(scene_name == NULL)
	// 	return error("[Scene::load_scene]","file null");

	std::ifstream reader;
	reader.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{	
		std::string line;
		reader.open(scene_name.c_str());
		while(!reader.eof())
		{
			getline(reader,line,'\n');
			std::cout << line << std::endl;
		}
		reader.close();

	}catch(std::ifstream::failure &e)
	{//strerror(errno);
		return error("[Scene::load_scene]","opening/reading/closing file");
	}
	return 0;
}