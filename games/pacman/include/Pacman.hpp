/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

#include "Object.hpp"

SpriteSheet pacmanSheet {
    {
        {NONE, YELLOW, YELLOW, YELLOW, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, NONE, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {NONE, YELLOW, YELLOW, YELLOW, NONE}
    },
    {
        {NONE, YELLOW, YELLOW, YELLOW, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {NONE, YELLOW, YELLOW, YELLOW, NONE}
    },
};


class Pacman : public Object {
	public:
		Pacman();
		~Pacman();

	protected:
	private:
};

#endif /* !PACMAN_HPP_ */
