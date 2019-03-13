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

	protected:
	private:
};

#endif /* !MAINMENUSCENE_HPP_ */

