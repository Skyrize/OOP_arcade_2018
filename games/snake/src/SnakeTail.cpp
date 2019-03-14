/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakeTail
*/

#include "SnakeTail.hpp"

Sprite snakeTailSprite {
    {NONE, GREEN, NONE},
    {NONE, GREEN, NONE},
    {GREEN, YELLOW, GREEN},
};

SnakeTail::SnakeTail()
: Object("SnakeTail", snakeTailSprite)
{
}

SnakeTail::~SnakeTail()
{
}

