/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** MenuModule.cpp
*/

#include "MenuModule.hpp"

MenuModule::MenuModule()
{

}

MenuModule::~MenuModule()
{

}

void MenuModule::init()
{

}

void MenuModule::stop()
{

}

const std::string &MenuModule::getName() const
{
    return _name;
}

void MenuModule::run(IDisplayModule *library)
{
    std::map<Input, bool> inputs = library->catchInput();

    this->scene.manageEvents(library, inputs);
    this->scene.update(library);
    this->scene.display(library);
}
