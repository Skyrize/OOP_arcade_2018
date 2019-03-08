/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

DisplayModule::DisplayModule()
{
}

DisplayModule::~DisplayModule()
{
}

void DisplayModule::init()
{
}

void DisplayModule::stop()
{
}

bool DisplayModule::isOpen()
{
    return true;
}

void DisplayModule::display()
{
}

void DisplayModule::clear()
{
}

void DisplayModule::drawText(int x, int y, const std::string &name) const
{
}

void DisplayModule::drawShape(int x, int y, std::vector<std::vector<Color> > pixels) const
{
}

std::map<Input, bool> DisplayModule::catchInput()
{
    return {};
}