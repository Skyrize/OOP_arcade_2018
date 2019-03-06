/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main
*/

#include "libcaca.hpp"

extern "C" IDisplayModule *entryPoint(void)
{
    return new DisplayModule();
}