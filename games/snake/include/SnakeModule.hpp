/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#ifndef SNAKEMODULE_HPP_
    #define SNAKEMODULE_HPP_

#include "IGameModule.hpp"
#include "Scene.hpp"

class SnakeModule : public IGameModule {
	public:
		SnakeModule();
		~SnakeModule();

        virtual void init();
        virtual void stop();
        virtual const std::string &getName() const;

        virtual void run(IDisplayModule *library, std::map<Input, bool> &inputs);

	protected:
        std::string _name = "SnakeModule";
		Scene scene;
	private:
};

#endif /* !SNAKEMODULE_HPP_ */

