/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanScene
*/

#ifndef PACMANSCENE_HPP_
    #define PACMANSCENE_HPP_

#include "Scene.hpp"
#include "Teleporter.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "Text.hpp"

class PacmanScene : public Scene {
	public:
		PacmanScene();
		~PacmanScene();
		float update(IDisplayModule *display) override;
		void manageEvents(std::map<Input, bool> &inputs) override;
		void addScore(int score) { _score += score; };
		int getScore() const { return _score; };
		void affraidGhosts();
		void unaffraidGhosts();
		void setNeedToOpen(bool need) { _needToOpen = need; };

	private:
		void initPacGums(void);
		bool ghostsInBox();
		int _score = 0;
		float _gateSecondsRemaining = 0;
		bool _needToClose = false;
		bool _needToOpen = true;
};

#endif /* !PACMANSCENE_HPP_ */
