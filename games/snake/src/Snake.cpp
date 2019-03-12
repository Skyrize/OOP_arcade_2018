/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#include "Snake.hpp"

SpriteSheet pacmanSheet {
    {
        {NONE, BLUE, BLUE, BLUE, NONE},
        {BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, NONE, NONE},
        {BLUE, BLUE, BLUE, BLUE, BLUE},
        {NONE, BLUE, BLUE, BLUE, NONE}
    },
    {
        {NONE, BLUE, BLUE, BLUE, NONE},
        {BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE},
        {NONE, BLUE, BLUE, BLUE, NONE}
    },
};


Snake::Snake()
: Object("Snake", pacmanSheet)
{
    this->movement.setfreeMoving(true);
    this->sprite.setLoop(true);
    this->sprite.setAnimationSpeed(0.3);
}

Snake::~Snake()
{
}
