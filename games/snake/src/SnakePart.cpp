/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakePart
*/

#include "SnakePart.hpp"

Sprite snakePartSprite {
    {GREEN, YELLOW, GREEN},
    {GREEN, GREEN, GREEN},
    {GREEN, YELLOW, GREEN},
};

SnakePart::SnakePart(const std::string &name, const std::pair<float, float> &position)
: Object(name, snakePartSprite, position)
{
}

SnakePart::~SnakePart()
{
}
