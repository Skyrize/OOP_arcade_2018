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

	protected:
        Arcade &arcade;
        std::vector<Text *> games;
	private:
};

#endif /* !GAMESELECTOR_HPP_ */
