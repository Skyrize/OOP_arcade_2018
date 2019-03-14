/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NextButton
*/

#ifndef NEXTBUTTON_HPP_
    #define NEXTBUTTON_HPP_

#include "Button.hpp"
#include "MainMenuScene.hpp"

class NextButton : public Button {
	public:
		NextButton(MainMenuScene &parent, const std::string &name, const std::pair<float, float> &position = {0.0, 0.0});
		~NextButton();

		virtual void buttonEvent();
	protected:
	private:
};

#endif /* !NextButton_HPP_ */

