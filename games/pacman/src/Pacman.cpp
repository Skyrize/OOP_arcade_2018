/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#include "Pacman.hpp"

SpriteSheet pacmanSheet {
    {
        {NONE, YELLOW, YELLOW, YELLOW, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, NONE, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {NONE, YELLOW, YELLOW, YELLOW, NONE}
    },
    {
        {NONE, YELLOW, YELLOW, YELLOW, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {NONE, YELLOW, YELLOW, YELLOW, NONE}
    },
};


Pacman::Pacman()
: Object("Pacman", pacmanSheet)
{
    this->movement.setfreeMoving(true);
    this->sprite.setLoop(true);
    this->sprite.setAnimationSpeed(0.3);
}

Pacman::~Pacman()
{
}
