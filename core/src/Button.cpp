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

void Button::hitEvent(Object *other)
{
    std::map<std::string, Object *> merge = this->parent.getObjects();
    std::map<std::string, Object *> objects = parent.getActualPannel()->getObjects();    

	merge.insert(objects.begin(), objects.end());

    (void)other;
    for (auto &e : merge) {
        if (e.second) {
            e.second->getAnimation().setAnimationSpeed(0.1);
            e.second->getAnimation().setNbLoop(4);
        }
    }
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
