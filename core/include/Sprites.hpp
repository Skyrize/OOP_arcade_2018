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

std::vector<std::vector<Color>> sprite_empty;

std::vector<std::vector<Color> > form {
    {NONE, NONE, RED, NONE, NONE},
    {NONE, RED, RED, RED, NONE},
    {RED, RED, RED, RED, RED},
    {RED, RED, RED, RED, RED}
};

#endif /* !SPRITES_HPP_ */

