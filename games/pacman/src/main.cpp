/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include "PacmanModule.hpp"

extern "C" IGameModule *entryPointGame(void)
{
    return new PacmanModule();
}