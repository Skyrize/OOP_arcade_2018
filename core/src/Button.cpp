/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Button
*/

#include "Button.hpp"
#include <iostream>

Button::Button(MainMenuScene &parent, const std::string &name, SpriteSheet &spriteSheet, const std::pair<float, float> &position)
: Object(name, spriteSheet, position), parent(parent)
{
    this->movement.setBlocking(true);
}

Button::Button(MainMenuScene &parent, const std::string &name, Sprite &sprite, const std::pair<float, float> &position)
: Object(name, sprite, position), parent(parent)
{
    this->movement.setBlocking(true);
}

void Button::eventHit(Object *other)
{
    parent.eventButtonTriggered();
    (void)other;
    this->hit = true;
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
