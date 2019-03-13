/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include "PacmanModule.hpp"

extern "C" IGameModule *entryPoint(void)
{
    return new PacmanModule();
}