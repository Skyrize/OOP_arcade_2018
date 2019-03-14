/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Arcade.cpp
*/

#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include "Arcade.hpp"

Arcade::Arcade(char *baseDisplayModule)
{
    std::string bdmString(baseDisplayModule);
    int hasFind = -1;

    loadLibraries();
    loadGames();
    for (size_t i = 0; i != libraries.size(); i++)
        if (libraries[i]->getFileName() == bdmString || libraries[i]->getFileName() == "./" + bdmString)
            hasFind = i;
    if (hasFind == -1) {
        libraries.push_back(new DLLoader<IDisplayModule>(bdmString));
        changeDisplay(libraries.size() - 1);
    } else {
        changeDisplay(hasFind);
    }
    this->game = new MenuModule;
}

Arcade::~Arcade()
{
}

void Arcade::launch()
{
    this->display->init();

    while (display->isOpen()) {
        event();
        display->clear();
        game->run(display, this->inputs);
        display->display();
    }
}

void Arcade::loadLibraries()
{
    DIR *dir = opendir("lib/");
    struct dirent *file;

    if (!dir) {
        std::cout << "Cannot open lib/ directory !" << std::endl;
    } else {
        while ((file = readdir(dir)) != NULL) {
            std::string fileName(file->d_name);
            if (fileName.find(".so") != std::string::npos) {
                libraries.push_back(new DLLoader<IDisplayModule>("lib/" + fileName));
                std::cout << "create lib loader for " + fileName << std::endl;
            }
        }
    }
}

void Arcade::loadGames()
{
    DIR *dir = opendir("games/");
    struct dirent *file;

    if (!dir) {
        std::cout << "Cannot open games/ directory !" << std::endl;
    } else {
        while ((file = readdir(dir)) != NULL) {
            std::string fileName(file->d_name);
            if (fileName.find(".so") != std::string::npos) {
                games.push_back(new DLLoader<IGameModule>("games/" + fileName));
                std::cout << "create game loader for " + fileName << std::endl;
            }
        }
    }
}

void Arcade::nextDisplay()
{
    if (this->actualLib == this->libraries.size() - 1) {
        changeDisplay(0);
    } else
        changeDisplay(actualLib + 1);
}

void Arcade::prevDisplay()
{
    if (this->actualLib == 0) {
        changeDisplay(this->libraries.size() - 1);
    } else
        changeDisplay(actualLib - 1);
}

void Arcade::nextGame()
{
    if (this->actualGame == this->games.size() - 1) {
        changeGame(0);
    } else
        changeGame(actualGame + 1);
}

void Arcade::prevGame()
{
    if (this->actualGame == 0) {
        changeGame(this->games.size() - 1);
    } else
        changeGame(actualGame - 1);
}

void Arcade::event()
{
    float actual = this->display->getTime();

    if (actual < previous)
        previous = 0;
    this->inputs = this->display->catchInput();
    remaining -= actual - previous;
    if (remaining <= 0) {
        if (inputs[L_KEY] == true ||
        inputs[O_KEY] == true ||
        inputs[P_KEY] == true ||
        inputs[K_KEY] == true ||
        inputs[M_KEY] == true) {
            if (inputs[L_KEY] == true) {
                prevGame();
            } else if (inputs[O_KEY] == true) {
                nextGame();
            } else if (inputs[P_KEY] == true) {
                goToMainMenu();
            }
            if (inputs[K_KEY] == true) {
                prevDisplay();
            } else if (inputs[M_KEY] == true) {
                nextDisplay();
            }
            remaining = 1;
        }
    }
    if (inputs[ESCAPE_KEY] == true)
        this->display->stop();
    previous = actual;
}
IDisplayModule *Arcade::changeDisplay(const size_t &index)
{
    if (this->display) {
        this->display->stop();
        delete(this->display);
    }
    this->libraries[actualLib]->stop();
    this->libraries[index]->init();
    this->display = this->libraries[index]->getInstance();
    this->display->init();
    this->actualLib = index;
    return this->display;
}

IGameModule *Arcade::changeGame(const size_t &index)
{
    this->display->restartTime();
    if (this->games.size() == 0) {
        return goToMainMenu();
    }
    if (this->game) {
        this->game->stop();
        delete(game);
    }
    this->games[index]->init();
    this->game = this->games[index]->getInstance();
    this->game->init();
    this->actualGame = index;
    return this->game;
}

IGameModule *Arcade::goToMainMenu()
{
    this->display->restartTime();
    this->game->stop();
    delete(this->game);
    this->game = new MenuModule();
    this->game->init();
    return this->game;
}