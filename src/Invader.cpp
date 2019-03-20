/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Invader
*/

#include "Invader.hpp"

SpriteSheet invaderSpriteSheet {
    {
        {NONE, NONE, RED, NONE, NONE},
        {NONE, RED, RED, RED, NONE},
        {RED, RED, RED, RED, RED},
        {RED, RED, RED, RED, RED}
    },
    {
        {NONE, NONE, YELLOW, NONE, NONE},
        {NONE, YELLOW, YELLOW, YELLOW, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW}
    },
    {
        {NONE, NONE, BLUE, NONE, NONE},
        {NONE, BLUE, BLUE, BLUE, NONE},
        {BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE}
    },
};

Invader::Invader(Scene &parent, const std::pair<float, float> &pos)
: Object("SpaceInvader", invaderSpriteSheet, pos),
parent(parent),
gun(*this, true, 1, 200, 0.2, 0.5, 1)
{
    movement.setFreeMoving(true);
    movement.setBlocking(true);
    sprite.setAnimationSpeed(0.4);
    sprite.setLoop(true);
}

Invader::~Invader()
{
}

float Invader::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float delta = Object::update(display, objects);

    if (gun.hasShot() == true) {
        if (gun.getFireTimer() <= 0) {
            gun.setHasShot(false);
        } else {
            gun.setFireTimer(gun.getFireTimer() - delta);
        }
    }
    return delta;
}

void Invader::manageEvents(std::map<Input, bool> &inputs)
{
    if (inputs[Input::SPACE_KEY] == true && gun.hasShot() == false)
        gun.shoot(std::pair<float, float>{0, -1});
    if (inputs[Input::UP_ARROW_KEY] == true || inputs[Input::LEFT_ARROW_KEY] == true || 
    inputs[Input::DOWN_ARROW_KEY] == true || inputs[Input::RIGHT_ARROW_KEY] == true) {
        if (inputs[Input::UP_ARROW_KEY] == true)
            movement.setSpeed(movement.getSpeed().first, -100);
        else if (inputs[Input::DOWN_ARROW_KEY] == true)
            movement.setSpeed(movement.getSpeed().first, 100);
        else
            movement.setSpeed(movement.getSpeed().first, 0);
        if (inputs[Input::LEFT_ARROW_KEY] == true)
            movement.setSpeed(-100, movement.getSpeed().second);
        else if (inputs[Input::RIGHT_ARROW_KEY] == true)
            movement.setSpeed(100, movement.getSpeed().second);
        else
            movement.setSpeed(0, movement.getSpeed().second);
    } else {
        movement.setSpeed(0, 0);
    }
}

Invader::ShootComponent &Invader::getGun()
{
    return gun;
}

Scene &Invader::getParent()
{
    return parent;
}