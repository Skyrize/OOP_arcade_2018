/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NextButton
*/

#include "NextButton.hpp"
#include <iostream>

static SpriteSheet nextButtonSheet {
    {
        {BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, NONE, NONE, NONE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE},
    },
    {
        {RED, RED, RED, RED, RED},
        {RED, NONE, NONE, NONE, RED},
        {RED, RED, RED, RED, RED},
    },
    {
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {YELLOW, NONE, NONE, NONE, YELLOW},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
    },
};

NextButton::NextButton(MainMenuScene &parent, const std::string &name, const std::pair<float, float> &position)
: Button(parent, name, nextButtonSheet, position)
{
    this->movement.setBlocking(true);
}

NextButton::~NextButton()
{
}

void NextButton::buttonEvent()
{
    parent.nextPannel();
}