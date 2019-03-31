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
    this->textPos = position;
}

Text::Text(const std::string &name, const std::string &text, int fontSize, Color color, Sprite &sprite, const std::pair<float, float> &position)
: Object(name, sprite, position),
text(text),
fontSize(fontSize),
color(color)
{
    this->textPos = position;
}

Text::~Text()
{
}

void Text::display(IDisplayModule *display)
{
    const std::pair<float, float> &pos = movement.getPosition();

    Object::display(display);
    if (GET_X(pos) != GET_X(textPos) || GET_Y(pos) != GET_Y(textPos))
        display->drawText(GET_X(textPos), GET_Y(textPos), text, fontSize, color);
    else
        display->drawText(GET_X(pos), GET_Y(pos), text, fontSize, color);
}

void Text::setText(const std::string &newText)
{
    this->text = newText;
}

const std::string &Text::getText()
{
    return this->text;
}