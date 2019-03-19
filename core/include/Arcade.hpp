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
#include "MenuModule.hpp"
#include "DLLoader.hpp"

class Arcade {
        private:
                size_t actualLib = 0;
                size_t actualGame = 0;
                float remaining = 0;
                float previous = 0;

                std::vector<DLLoader<IDisplayModule> *> libraries;
                std::vector<DLLoader<IGameModule> *> games;

                IDisplayModule *display = nullptr;
                IGameModule *game = nullptr;

                std::map<Input, bool> inputs;

	public:
		Arcade(char *baseDisplayModule);
		~Arcade();

                void launch();
                void loadLibraries();
                void loadGames();

                IDisplayModule *changeDisplay(const size_t &index);
                IGameModule *changeGame(const size_t &index);

                void event();
                IGameModule *goToMainMenu();

                void nextDisplay();
                void prevDisplay();
                void nextGame();
                void prevGame();
};

#endif /* !ARCADE_HPP_ */

