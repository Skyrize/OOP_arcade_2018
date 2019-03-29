/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** TextBox
*/

#ifndef TEXTBOX_HPP_
    #define TEXTBOX_HPP_

#include "Text.hpp"

class TextBox : public Object {
	public:
		TextBox(std::string &playerName, const std::pair<float, float> &pos);
		~TextBox();

        virtual void manageEvents(std::map<Input, bool> &inputs);
		virtual void display(IDisplayModule *display);
        void addChar(char character);
        void removeChar();
        void updateText();
		void eventHit(Object *other);
	protected:
        std::string &playerName;
        Text *text;
        int actualChar;
	private:
};

#endif /* !TEXTBOX_HPP_ */
