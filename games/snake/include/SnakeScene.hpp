/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakeScene
*/

#ifndef SNAKESCENE_HPP_
    #define SNAKESCENE_HPP_

#include "Scene.hpp"

class SnakeScene : public Scene {
	public:
		SnakeScene();
		~SnakeScene();

		virtual void manageEvents(std::map<Input, bool> &inputs);
	protected:
	private:
};

#endif /* !SNAKESCENE_HPP_ */
