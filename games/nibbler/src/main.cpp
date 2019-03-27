/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include "SnakeModule.hpp"

extern "C" IGameModule *entryPoint(void)
{
    return new SnakeModule();
}