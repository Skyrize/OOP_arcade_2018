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

	public:
		Scene(const std::string &name, std::vector<std::vector<Color> > &sprite, std::pair<float, float> position = {0.0, 0.0});
		virtual ~Scene();

		virtual void display(IDisplayModule *display);
		virtual void update(IDisplayModule *display);
		Object *getObject(const std::string &name);
		Object *addObject(Object *newObject);
		Object *addObject(const std::string &name, std::vector<std::vector<Color> > &sprite, std::pair<float, float> position = {0.0, 0.0});
		void removeObject(const std::string &name);
};

#endif /* SRC_SCENE_HPP_ */
