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
#include "DLLoader.hpp"

class Arcade {
	private:
        std::map<std::string, DLLoader<IDisplayModule> *> libraries;
        std::map<std::string, DLLoader<IGameModule> *> games;

        IDisplayModule *display = nullptr;
        IGameModule *game = nullptr;

	public:
		Arcade(char *baseDisplayModule);
		~Arcade();

        void launch();
        void loadLibraries();
        void loadGames();

        IDisplayModule *changeDisplay(const std::string &name);
        IGameModule *changeGame(const std::string &name);
};

#endif /* !ARCADE_HPP_ */

