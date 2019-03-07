/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

class Arcade {
	public:
		Arcade();
		~Arcade();

	protected:
	private:
        IDisplayModule *graphical = nullptr;
        IGameModule *game = nullptr;
};

#endif /* !ARCADE_HPP_ */

