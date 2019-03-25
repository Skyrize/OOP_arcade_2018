/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** BackButton
*/

#include "BackButton.hpp"
#include <iostream>

static SpriteSheet backButtonSheet {
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

BackButton::BackButton(MainMenuScene &parent, const std::string &name, const std::pair<float, float> &position)
: Button(parent, name, backButtonSheet, position)
{
    this->movement.setBlocking(true);
}

BackButton::~BackButton()
{
}

void BackButton::buttonEvent()
{
    parent.previousPannel();
}