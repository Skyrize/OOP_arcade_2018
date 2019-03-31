/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** GameSelector
*/

#ifndef GAMESELECTOR_HPP_
    #define GAMESELECTOR_HPP_

#include "Text.hpp"
#include "Arcade.hpp"

class GameSelector : public Object {
	public:
		GameSelector(Arcade &arcade);
		~GameSelector();

		void eventHit(Object *other);
		virtual void buttonEvent();
		virtual void display(IDisplayModule *display);
		void updatePositions();
	protected:
        Arcade &arcade;
        std::vector<Text *> games;
		bool hit = false;
	private:
};

#endif /* !GAMESELECTOR_HPP_ */
