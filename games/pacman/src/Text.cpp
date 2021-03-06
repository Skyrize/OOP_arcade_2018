/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Text
*/

#include "Text.hpp"

Text::Text(const std::string &name, const std::string &text, int fontSize, Color color, SpriteSheet &spriteSheet, const std::pair<float, float> &position)
: Object(name, spriteSheet, position),
text(text),
fontSize(fontSize),
color(color)
{
}

Text::Text(const std::string &name, const std::string &text, int fontSize, Color color, Sprite &sprite, const std::pair<float, float> &position)
: Object(name, sprite, position),
text(text),
fontSize(fontSize),
color(color)
{
}

Text::~Text()
{
}

void Text::display(IDisplayModule *display)
{
    const std::pair<float, float> &pos = movement.getPosition();

    Object::display(display);
    display->drawText(GET_X(pos), GET_Y(pos), text, fontSize, color);
}

void Text::setText(const std::string &newText)
{
    this->text = newText;
}