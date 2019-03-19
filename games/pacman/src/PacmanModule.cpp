/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanModule
*/

#include "PacmanModule.hpp"
#include "Pacman.hpp"

Sprite none;

PacmanModule::PacmanModule()
{
}

PacmanModule::~PacmanModule()
{
}

void PacmanModule::init()
{

}

void PacmanModule::stop()
{

}

const std::string &PacmanModule::getName() const
{
    return _name;
}

void PacmanModule::run(IDisplayModule *library, std::map<Input, bool> &inputs)
{
    this->scene.manageEvents(inputs);
    this->scene.update(library);
    this->scene.display(library);
}
