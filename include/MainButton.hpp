/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MainButton
*/

#ifndef MAINBUTTON_HPP_
    #define MAINBUTTON_HPP_

#include "NextButton.hpp"
#include "MainMenuScene.hpp"

class MainButton : public NextButton {
	public:
		MainButton(MainMenuScene &parent, const std::string &name, const std::pair<float, float> &position = {0.0, 0.0});
		~MainButton();

	protected:
	private:
};

#endif /* !MainButton_HPP_ */

