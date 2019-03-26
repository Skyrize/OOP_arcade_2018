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

void MenuModule::init(const std::string &playerName, const int &highScore)
{
    (void)playerName;
    (void)highScore;
}

void MenuModule::stop()
{
}

const std::string &MenuModule::getName() const
{
    return _name;
}

int MenuModule::getHighScore() const
{
    return 0;
}

void MenuModule::run(IDisplayModule *library, std::map<Input, bool> &inputs)
{
    this->scene.manageEvents(inputs);
    this->scene.update(library);
    this->scene.display(library);
}
