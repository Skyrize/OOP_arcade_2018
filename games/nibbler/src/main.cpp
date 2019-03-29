/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include "SnakeModule.hpp"

extern "C" IGameModule *entryPointGame(void)
{
    return new SnakeModule();
}