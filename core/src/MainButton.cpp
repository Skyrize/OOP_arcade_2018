/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MainButton
*/

#include "MainButton.hpp"
#include <iostream>

static SpriteSheet mainButtonSheet {
    {
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE},
        {NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE},
        {BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE},
        {NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE},
        {NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
    },
};

MainButton::MainButton(MainMenuScene &parent, const std::string &name, const std::pair<float, float> &position)
: NextButton(parent, name, position)
{
    this->sprite.changeSpriteSheet(mainButtonSheet);
}

MainButton::~MainButton()
{
}
