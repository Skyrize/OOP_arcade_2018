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
#include "ScorePannel.hpp"

class PacmanScene : public Scene {
	public:
		PacmanScene();
		~PacmanScene();
		float update(IDisplayModule *display) override;
		void manageEvents(std::map<Input, bool> &inputs) override;
		void addScore(int score);
		int getScore() const { return _score; };
		void affraidGhosts();
		void unaffraidGhosts();
		void setNeedToOpen(bool need) { _needToOpen = need; };
		void initGame();
		bool anyPacGumsLeft();

		int getActualHighScore() const { return _actualHighScore; };
		void setHighScore(std::pair<std::string, int> highScore) { _highScore = highScore; };
		std::pair<std::string, int> getHighScore() const { return _highScore; };

	private:
		void initPacGums(void);
		void initGhosts(void);
		bool ghostsInBox();
		void updateGate(float);
		void updateRestart(float);

		int _score = 0;
		float _gateSecondsRemaining = 0;
		bool _needToClose = false;
		bool _needToOpen = true;
		bool _startMenu = 1;
		bool _endMenu = 0;
		float _restartSecondsRemaining = 0;
		int _actualHighScore = 0;
		std::pair<std::string, int> _highScore;
};

#endif /* !PACMANSCENE_HPP_ */
