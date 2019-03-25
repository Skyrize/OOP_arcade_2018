/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_

#include "Object.hpp"

class Text : public Object {
	public:
		Text(const std::string &name, const std::string &text, int fontSize, Color color, SpriteSheet &backgroundSheet, const std::pair<float, float> &position = {0.0, 0.0});
		Text(const std::string &name, const std::string &text, int fontSize, Color color, Sprite &backgroundSheetsprite, const std::pair<float, float> &position = {0.0, 0.0});
		~Text();
        virtual void display(IDisplayModule *display);
        virtual void setText(const std::string &newText);

	protected:
        std::string text;
        int fontSize;
        Color color;
	private:
};

#endif /* !TEXT_HPP_ */
