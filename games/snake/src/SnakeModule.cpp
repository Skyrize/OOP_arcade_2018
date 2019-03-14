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

void SnakeModule::init()
{

}

void SnakeModule::stop()
{

}

const std::string &SnakeModule::getName() const
{
    return _name;
}

void SnakeModule::run(IDisplayModule *library, std::map<Input, bool> &inputs)
{
    this->scene.manageEvents(inputs);
    this->scene.update(library);
    this->scene.display(library);
}
