/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

#include "Object.hpp"
#include "MainMenuScene.hpp"

class Button : public Object {
	public:
		Button(MainMenuScene &parent, const std::string &name, SpriteSheet &spriteSheet, const std::pair<float, float> &position = {0.0, 0.0});
		Button(MainMenuScene &parent, const std::string &name, Sprite &sprite, const std::pair<float, float> &position = {0.0, 0.0});

		virtual ~Button() = default;
		void hitEvent(Object *other);
		float update(IDisplayModule *display, std::map<std::string, Object *> &objects);
		virtual void buttonEvent() = 0;
	protected:
        MainMenuScene &parent;
		bool hit = false;
	private:
};

#endif /* !Button_HPP_ */
