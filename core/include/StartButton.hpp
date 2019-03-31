/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** StartButton
*/

#ifndef STARTBUTTON_HPP_
    #define STARTBUTTON_HPP_

#include "Text.hpp"
#include "Arcade.hpp"

class StartButton : public Text {
	public:
		StartButton(MenuModule &parent, Arcade &arcade);
		~StartButton() = default;

		void eventHit(Object *other);
		virtual void buttonEvent();
		float update(IDisplayModule *display, std::map<std::string, Object *> &objects);
	protected:
        MenuModule &parent;
        Arcade &arcade;
		bool hit = false;
	private:
};

#endif /* !STARTBUTTON_HPP_ */
