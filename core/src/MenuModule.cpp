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

void MenuModule::eventHandler(IDisplayModule *library, std::map<Input, bool> &inputs)
{
    if (inputs[Input::ESCAPE_KEY] == true)
        library->stop();
}

void MenuModule::run(IDisplayModule *library)
{
    std::vector<std::vector<Color> > form{
        {WHITE, WHITE, RED, WHITE, WHITE},
        {WHITE, RED, RED, RED, WHITE},
        {RED, RED, RED, RED, RED}
    };
    std::map<Input, bool> inputs = library->catchInput();

    eventHandler(library, inputs);
    library->drawShape(2, 2, form);
}
