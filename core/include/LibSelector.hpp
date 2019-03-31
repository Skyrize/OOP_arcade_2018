/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** LibSelector
*/

#ifndef LIBSELECTOR_HPP_
    #define LIBSELECTOR_HPP_

#include "Text.hpp"
#include "Arcade.hpp"

class LibSelector : public Object {
	public:
		LibSelector(MenuModule &parent, Arcade &arcade);
		~LibSelector();

		void eventHit(Object *other);
		virtual void buttonEvent();
		virtual void display(IDisplayModule *display);

		void updatePositions();
	protected:
		MenuModule &parent;
        Arcade &arcade;
        std::vector<Text *> libs;
		bool hit = false;
	private:
};

#endif /* !LIBSELECTOR_HPP_ */
