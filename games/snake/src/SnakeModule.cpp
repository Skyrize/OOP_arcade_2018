/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SnakeModule
*/

#include "SnakeModule.hpp"
#include "Snake.hpp"
#include <iostream>

Sprite none;

SnakeModule::SnakeModule()
{
}

SnakeModule::~SnakeModule()
{
}

void SnakeModule::init(const std::string &playerName, const int &highScore)
{
    (void)playerName;
    (void)highScore;
}

void SnakeModule::stop()
{
}

const std::string &SnakeModule::getName() const
{
    return _name;
}

int SnakeModule::getHighScore() const
{
    return 0;
}

void SnakeModule::run(IDisplayModule *library, std::map<Input, bool> &inputs)
{
    this->scene.manageEvents(inputs);
    this->scene.update(library);
    this->scene.display(library);
}
