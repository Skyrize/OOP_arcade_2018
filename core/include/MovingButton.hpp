/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MovingButton
*/

#ifndef MovingButton_HPP_
    #define MovingButton_HPP_

#include "Button.hpp"

class MovingButton : public Button {
	public:
		MovingButton(MainMenuScene &parent, const int &targetPannelIndex, const int &startOffset, const int &endOffset, const std::string &name, SpriteSheet &spriteSheet, const std::pair<float, float> &position = {0.0, 0.0});
		MovingButton(MainMenuScene &parent, const int &targetPannelIndex, const int &startOffset, const int &endOffset, const std::string &name, Sprite &sprite, const std::pair<float, float> &position = {0.0, 0.0});

		virtual ~MovingButton() = default;
        void eventReachedDestination();
	protected:
        int startOffset;
        int endOffset;
		std::pair<float, float> basePosition;
	private:
};

#endif /* !MovingButton_HPP_ */
