/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Scene.cpp
*/

#include "Scene.hpp"
#include <iostream>

Scene::Scene(const std::string &name, Sprite &sprite, std::pair<float, float> position)
: Object(name, sprite, position)
{
}

Scene::Scene(const std::string &name, SpriteSheet &spriteSheet, std::pair<float, float> position)
: Object(name, spriteSheet, position)
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

float Scene::update(IDisplayModule *display)
{
    float delta = Object::update(display, objects);

	for (auto &e : objects)
		if (e.second)
			e.second->update(display, objects);
	return delta;
}

void Scene::manageEvents(std::map<Input, bool> &inputs)
{
	for (auto &e : objects)
		if (e.second)
			e.second->manageEvents(inputs);
}

Object *Scene::getObject(const std::string &name)
{
	return objects[name];
}

Object *Scene::addObject(Object *newObject)
{
	if (objects.find(newObject->getName()) != objects.end())
		delete(objects[newObject->getName()]);
	objects[newObject->getName()] = newObject;
    return newObject;
}

Object *Scene::addObject(const std::string &name, Sprite &sprite, std::pair<float, float> position)
{
	if (objects.find(name) != objects.end())
		delete(objects[name]);
	objects[name] = new Object(name, sprite, position);
    return objects[name];
}

Object *Scene::addObject(const std::string &name, SpriteSheet &spriteSheet, std::pair<float, float> position)
{
	if (objects.find(name) != objects.end())
		delete(objects[name]);
	objects[name] = new Object(name, spriteSheet, position);
    return objects[name];
}

void Scene::removeObject(const std::string &name)
{
	if (objects.find(name) != objects.end()) {
		toRemove.push_back(objects[name]);
		objects.erase(objects.find(name));
	}
}

void Scene::removeAllObjects()
{
	for (auto &i: this->objects) {
		removeObject(i.first);
	}
}

void Scene::removeObjects()
{
	for (auto &e : toRemove)
		delete(e);
	this->toRemove.clear();
}

std::map<std::string, Object *> &Scene::getObjects()
{
	return this->objects;
}