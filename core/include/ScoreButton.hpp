/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreButton
*/

#ifndef SCOREBUTTON_HPP_
    #define SCOREBUTTON_HPP_

#include "ScoreBoard.hpp"

class ScoreBoard;
class ScoreButton : public Object {
	public:
		ScoreButton(ScoreBoard &parent, void (ScoreBoard::*fptr)(), SpriteSheet &spriteSheet, const std::pair<float, float> &position = {0.0, 0.0});
		ScoreButton(ScoreBoard &parent, void (ScoreBoard::*fptr)(), Sprite &sprite, const std::pair<float, float> &position = {0.0, 0.0});
		~ScoreButton();

		virtual void eventHit(Object *other);

	protected:
        ScoreBoard &parent;
        void (ScoreBoard::*fptr)();
	private:
};

#endif /* !SCOREBUTTON_HPP_ */
