/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScorePannel
*/

#ifndef SCOREPANNEL_HPP_
#define SCOREPANNEL_HPP_

#include "PacmanScene.hpp"
#include "Text.hpp"

class PacmanScene;

class ScorePannel : public Scene {
	public:
		ScorePannel(std::pair<int, int> pos, PacmanScene *parent);
		~ScorePannel();

		float update(IDisplayModule *display) override;

	private:
		PacmanScene *_parent;
};

#endif /* !SCOREPANNEL_HPP_ */
