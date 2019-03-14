/*
 ** EPITECH PROJECT, 2019
 ** ESH
 ** File description: Created on: 26 janv. 2019
 ** Scene.hpp
 */

#ifndef SRC_SCENE_HPP_
#define SRC_SCENE_HPP_

#include <map>
#include "Object.hpp"

class Scene: public Object {
	protected:
		std::map<std::string, Object *> objects;
		std::vector<Object *> toRemove;

	public:
		Scene(const std::string &name, Sprite &sprite, std::pair<float, float> position = {0.0, 0.0});
		Scene(const std::string &name, SpriteSheet &spriteSheet, std::pair<float, float> position = {0.0, 0.0});
		virtual ~Scene();

		virtual void display(IDisplayModule *display);
		virtual float update(IDisplayModule *display);
		Object *getObject(const std::string &name);
		Object *addObject(Object *newObject);
		Object *addObject(const std::string &name, Sprite &sprite, std::pair<float, float> position = {0.0, 0.0});
		Object *addObject(const std::string &name, SpriteSheet &spriteSheet, std::pair<float, float> position = {0.0, 0.0});
		void removeObject(const std::string &name);
		void removeObjects();

		std::map<std::string, Object *> &getObjects();
};

#endif /* SRC_SCENE_HPP_ */
