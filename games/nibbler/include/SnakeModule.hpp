/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#ifndef SNAKEMODULE_HPP_
    #define SNAKEMODULE_HPP_

#include "IGameModule.hpp"
#include "SnakeScene.hpp"

class SnakeModule : public IGameModule {
	public:
		SnakeModule();
		~SnakeModule();

        virtual void init(const std::string &playerName, const int &highScore);
        virtual void stop();
        virtual const std::string &getName() const;
        virtual int getHighScore() const;
        virtual void restart() const;
        virtual void run(IDisplayModule *library, std::map<Input, bool> &inputs);

	protected:
        std::string _name = "nibbler";
		SnakeScene scene;
	private:
};

#endif /* !SNAKEMODULE_HPP_ */

