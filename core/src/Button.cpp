/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Button
*/

#include "Button.hpp"
#include <iostream>

Button::Button(MainMenuScene &parent, const int &targetPannelIndex, const std::string &name, SpriteSheet &spriteSheet, const std::pair<float, float> &position)
: Object(name, spriteSheet, position), parent(parent),
targetPannelIndex(targetPannelIndex)
{
    this->movement.setBlocking(true);
}

Button::Button(MainMenuScene &parent, const int &targetPannelIndex, const std::string &name, Sprite &sprite, const std::pair<float, float> &position)
: Object(name, sprite, position), parent(parent),
targetPannelIndex(targetPannelIndex)
{
    this->movement.setBlocking(true);
}

void Button::eventHit(Object *other)
{
    if (other->getName().find("AStar") != std::string::npos || other->getName() == "mainPannel-MainButton")
        return;
    parent.eventButtonTriggered();
    this->hit = true;
}

void Button::buttonEvent()
{
    parent.goToPannel(targetPannelIndex);
}

float Button::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float delta = Object::update(display, objects);
    
    if (sprite.isAnimated() == false && hit == true) {
        hit = false;
		buttonEvent();
    }
    return delta;
}
