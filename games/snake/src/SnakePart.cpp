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

SnakePart::SnakePart(Snake &head, SnakePart *next, const std::pair<float, float> &position)
: Object("SnakePart-" + std::to_string(head.getNbParts()), snakePartSprite, position),
head(head),
nextPart(next)
{
}

SnakePart::~SnakePart()
{
}

bool SnakePart::fullyInBlock()
{
    const std::pair<float, float> &pos = movement.getPosition();

    if ((int)(GET_X(pos) + 1) % 3 == 0 && (int)(GET_Y(pos) - 1) % 3 == 0)
        return true;
    return false;
}

void SnakePart::replaceInBlock()
{

}
