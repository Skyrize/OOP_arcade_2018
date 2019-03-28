/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#ifndef PACMANMODULE_HPP_
#define PACMANMODULE_HPP_

#include "IGameModule.hpp"
#include "PacmanScene.hpp"

class PacmanModule : public IGameModule {
	public:
		PacmanModule();
		~PacmanModule();

        virtual void init(const std::string &playerName, const int &highScore);
        virtual void stop();
        virtual const std::string &getName() const;
        virtual int getHighScore() const;
        virtual void restart() const;

        virtual void run(IDisplayModule *library, std::map<Input, bool> &inputs);

	protected:
        std::string _name = "Pacman";
		PacmanScene scene;
};

#endif /* !PACMANMODULE_HPP_ */

