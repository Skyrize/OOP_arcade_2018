/*
*** EP
*ITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanModule
*/

#include "PacmanModule.hpp"
#include "Pacman.hpp"

PacmanModule::PacmanModule()
{
}

PacmanModule::~PacmanModule()
{
}

void PacmanModule::init(const std::string &playerName, const int &highScore)
{
    this->scene.setHighScore({playerName, highScore});
}

void PacmanModule::stop()
{
}

const std::string &PacmanModule::getName() const
{
    return _name;
}

int PacmanModule::getHighScore() const
{
    return this->scene.getActualHighScore();
}

void PacmanModule::run(IDisplayModule *library, std::map<Input, bool> &inputs)
{
    this->scene.manageEvents(inputs);
    this->scene.update(library);
    this->scene.display(library);
}

void PacmanModule::restart() const
{
}