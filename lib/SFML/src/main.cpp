/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main
*/

#include "SFML.hpp"

extern "C" IDisplayModule *entryPointDisplay(void)
{
    return new DisplayModule();
}