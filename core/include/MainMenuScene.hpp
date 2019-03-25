/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MainMenuScene
*/

#ifndef MAINMENUSCENE_HPP_
    #define MAINMENUSCENE_HPP_

#include "Scene.hpp"

class MainMenuScene : public Scene {
	public:
		MainMenuScene();
		~MainMenuScene();
        
		virtual void manageEvents(std::map<Input, bool> &inputs);
		void previousPannel();
		void nextPannel();
		Scene *getActualPannel();

		virtual void display(IDisplayModule *display);
		virtual float update(IDisplayModule *display);
		void eventButtonTriggered();
	protected:
		float starSpawnTimer = 0;
		int nbStars = 0;
		size_t actualPannel = 0;
		std::vector<Scene *> pannels;

		std::string playerName;
	private:
};

#endif /* !MAINMENUSCENE_HPP_ */

