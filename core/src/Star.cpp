/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Star
*/

#include "Star.hpp"

static SpriteSheet starSpriteSheet {
    {
        {WHITE}
    },
    {
        {BLUE}
    }
};

Star::Star(const std::string &name)
: Object(name, starSpriteSheet)
{
    this->movement.setBlocking(false);
    this->sprite.setLoop(true);
    this->sprite.setAnimationSpeed(1);
    respawn();
}

void Star::respawn()
{
    float randomPos = rand() % 100;
    float randY = rand() % 10;

    this->movement.setPosition(randomPos, -randY);
    this->movement.setDestination(std::pair<float, float>{randomPos, 58}, 0.5);
}

void Star::eventReachedDestination()
{
    respawn();
}