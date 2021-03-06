/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

#include "Object.hpp"
#include "MenuModule.hpp"

class Button : public Object {
	public:
		Button(MenuModule &parent, const int &targetPannelIndex, const std::string &name, SpriteSheet &spriteSheet, const std::pair<float, float> &position = {0.0, 0.0});
		Button(MenuModule &parent, const int &targetPannelIndex, const std::string &name, Sprite &sprite, const std::pair<float, float> &position = {0.0, 0.0});

		virtual ~Button() = default;
		void eventHit(Object *other);
		float update(IDisplayModule *display, std::map<std::string, Object *> &objects);
		virtual void buttonEvent();
	protected:
        MenuModule &parent;
		int targetPannelIndex;
		bool hit = false;
	private:
};

#endif /* !Button_HPP_ */

