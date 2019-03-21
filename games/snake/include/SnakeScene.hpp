/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakeScene
*/

#ifndef SNAKESCENE_HPP_
    #define SNAKESCENE_HPP_

#include "Scene.hpp"
#include "Text.hpp"

class SnakeScene : public Scene {
	public:
		SnakeScene();
		~SnakeScene();

		virtual void manageEvents(std::map<Input, bool> &inputs);

		void eventFruitEaten();
		void replaceFruit();
		void addPoints();

    	void openEndMenu();
		void launchSnake();
		void killSnake();
	protected:
		Object *fruit;
		Text *score;
		int scoreValue = 0;
	private:
};

#endif /* !SNAKESCENE_HPP_ */
