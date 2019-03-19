/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanScene
*/

#ifndef PACMANSCENE_HPP_
    #define PACMANSCENE_HPP_

#include "Scene.hpp"

class PacmanScene : public Scene {
	public:
		PacmanScene();
		~PacmanScene();
		void manageEvents(std::map<Input, bool> &inputs) override;
};

#endif /* !PACMANSCENE_HPP_ */
