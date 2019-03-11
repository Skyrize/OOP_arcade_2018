/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sprites
*/

#ifndef SPRITES_HPP_
    #define SPRITES_HPP_

#include <vector>
#include "Colors.hpp"

typedef std::vector<std::vector<Color>> Sprite;
typedef std::vector<Sprite> SpriteSheet;

Sprite sprite_empty;

Sprite form {
    {NONE, NONE, RED, NONE, NONE},
    {NONE, NONE, NONE, RED, NONE},
    {RED, RED, RED, RED, RED},
    {NONE, NONE, NONE, RED, RED}
};

SpriteSheet sheet {
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

SpriteSheet pacmanSheet {
    {
        {NONE, YELLOW, YELLOW, YELLOW, NONE},
        {NONE, NONE, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, NONE, NONE},
        {NONE, NONE, YELLOW, YELLOW, YELLOW},
        {NONE, YELLOW, YELLOW, YELLOW, NONE}
    },
    {
        {NONE, YELLOW, YELLOW, YELLOW, NONE},
        {NONE, NONE, YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
        {NONE, NONE, YELLOW, YELLOW, YELLOW},
        {NONE, YELLOW, YELLOW, YELLOW, NONE}
    },
};

SpriteSheet pacmanSheet2 {
    {
        {NONE, RED, RED, RED, NONE},
        {NONE, NONE, RED, RED, RED},
        {RED, RED, RED, NONE, NONE},
        {NONE, NONE, RED, RED, RED},
        {NONE, RED, RED, RED, NONE}
    },
    {
        {NONE, RED, RED, RED, NONE},
        {NONE, NONE, RED, RED, RED},
        {RED, RED, RED, RED, RED},
        {NONE, NONE, RED, RED, RED},
        {NONE, RED, RED, RED, NONE}
    },
};

#endif /* !SPRITES_HPP_ */

