/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** BackButton
*/

#ifndef BACKBUTTON_HPP_
    #define BACKBUTTON_HPP_

#include "Button.hpp"
#include "MainMenuScene.hpp"

class BackButton : public Button {
	public:
		BackButton(MainMenuScene &parent, const std::string &name, const std::pair<float, float> &position = {0.0, 0.0});
		~BackButton();

		virtual void buttonEvent();
	protected:
	private:
};

#endif /* !BackButton_HPP_ */

