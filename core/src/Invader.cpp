/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Invader
*/

#include "Invader.hpp"

SpriteSheet invaderSpriteSheet {
    {
        {NONE, NONE, NONE,  RED, NONE, NONE, NONE},
        {NONE, NONE,  RED,  RED,  RED, NONE, NONE},
        {NONE,  RED,  RED,WHITE,  RED,  RED, NONE},
        { RED,  RED,WHITE,WHITE,WHITE,  RED,  RED},
        { RED,  RED,  RED,  RED,  RED,  RED,  RED},
        {NONE,  RED, NONE,  RED, NONE,  RED, NONE}
    },
    {
        {NONE, NONE, NONE,  RED, NONE, NONE, NONE},
        {NONE, NONE,  RED,  RED,  RED, NONE, NONE},
        {NONE,  RED,  RED, BLUE,  RED,  RED, NONE},
        { RED,  RED, BLUE, BLUE, BLUE,  RED,  RED},
        { RED,  RED,  RED,  RED,  RED,  RED,  RED},
        {NONE,  RED, NONE,  RED, NONE,  RED, NONE}
    },
};

static const std::pair<float, float> lockPos0 = {11, 40};
static const std::pair<float, float> lockPos1 = {28, 40};
static const std::pair<float, float> lockPos2 = {46, 40};
static const std::pair<float, float> lockPos3 = {63, 40};
static const std::pair<float, float> lockPos4 = {81, 40};
static const std::pair<float, float> lockPoses[5] = {lockPos0, lockPos1, lockPos2, lockPos3, lockPos4};

Invader::Invader(Scene &parent, const std::pair<float, float> &pos)
: Object("SpaceInvader", invaderSpriteSheet, pos),
parent(parent),
gun(*this, true, 1, 200, 0.2, 0.5, 1)
{
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
        gun.shoot(std::pair<float, float>{0, -1}, std::pair<float, float>{movement.getPosition().first + 3, movement.getPosition().second - 2});
    if (inputs[Input::LEFT_ARROW_KEY] == true || inputs[Input::RIGHT_ARROW_KEY] == true) {
        if (inputs[Input::LEFT_ARROW_KEY] == true && lockPos != 0) {
            lockPos--;
            movement.setDestination(lockPoses[lockPos], 0.1);
        } else if (inputs[Input::RIGHT_ARROW_KEY] == true && lockPos != 4) {
            lockPos++;
            movement.setDestination(lockPoses[lockPos], 0.1);
        }
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

void Invader::replaceCenter()
{
    lockPos = 2;
    movement.setPosition(GET_X(lockPos2), GET_Y(lockPos2));
}