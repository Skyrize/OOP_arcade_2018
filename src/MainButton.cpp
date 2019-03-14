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
        { NONE,  NONE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  NONE,  NONE},
        { NONE, WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED, WHITE,  NONE},
        {WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED, WHITE},
        {WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED, WHITE},
        {WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED, WHITE},
        {WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED, WHITE},
        { NONE, WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED, WHITE,  NONE},
        { NONE,  NONE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  NONE,  NONE},
    },
    {
        { NONE,  NONE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  NONE,  NONE},
        { NONE,  BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE,  NONE},
        { BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE},
        { BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE},
        { BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE},
        { BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE},
        { NONE,  BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE,  NONE},
        { NONE,  NONE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  NONE,  NONE},
    },
    {
        { NONE,  NONE,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  NONE,  NONE},
        { NONE,  CYAN, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  CYAN,  NONE},
        { CYAN, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  CYAN},
        { CYAN, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  CYAN},
        { CYAN, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  CYAN},
        { CYAN, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  CYAN},
        { NONE,  CYAN, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,  CYAN,  NONE},
        { NONE,  NONE,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  CYAN,  NONE,  NONE},
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
