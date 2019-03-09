/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Scene.cpp
*/

#include "Scene.hpp"

Scene::Scene(const std::string &name, std::vector<std::vector<Color> > &sprite, std::pair<float, float> position)
: Object(name, sprite, position)
{
}

Scene::~Scene()
{
	for (auto &e : objects)
		if (e.second)
			delete(e.second);
}

void Scene::display(IDisplayModule *display)
{
	Object::display(display);
	for (auto &e : objects)
		if (e.second)
			e.second->display(display);
}

void Scene::update(IDisplayModule *display)
{
	for (auto &e : objects)
		if (e.second)
			e.second->update(display, objects);
}

Object *Scene::getObject(const std::string &name)
{
	return objects[name];
}

Object *Scene::addObject(Object *newObject)
{
	if (objects[newObject->getName()] != nullptr)
		delete(objects[newObject->getName()]);
	objects[newObject->getName()] = newObject;
    return newObject;
}

Object *Scene::addObject(const std::string &name, std::vector<std::vector<Color> > &sprite, std::pair<float, float> position)
{
	if (objects[name] != nullptr)
		delete(objects[name]);
	objects[name] = new Object(name, sprite, position);
    return objects[name];
}

void Scene::removeObject(const std::string &name)
{
	if (objects[name] != nullptr) {
		delete(objects[name]);
		objects[name] = nullptr;
	}
}
