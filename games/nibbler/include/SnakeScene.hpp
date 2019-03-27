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

		void launchSnake();
		void killSnake();
		void changeMode();

		void previousMap();
		void nextMap();
		void unloadMap();
		void loadMap();

		int getHighScore() const;

	protected:
		Object *startMenu;
		Object *endMenu;
		Object *fruit;
		Text *score;
		int scoreValue = 0;
		int highScore = 0;
		Text *speedMode;
		bool speedModeValue = false;

		size_t actualMap = 0;
		Text *displayedMap;
		std::vector<std::vector<Object *>> maps;
	private:
};

#endif /* !SNAKESCENE_HPP_ */
