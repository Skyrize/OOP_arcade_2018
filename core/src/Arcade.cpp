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

    loadLibraries();
    loadGames();
    if (!libraries[bdmString]) {
        libraries[bdmString] = new DLLoader<IDisplayModule>(bdmString);
    }
    this->display = libraries[bdmString]->getInstance();
    this->game = this->mainMenu;
}

Arcade::~Arcade()
{
}

void Arcade::launch()
{
    this->display->init();

    while (display->isOpen()) {
        display->clear();
        game->run(display);
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
                libraries[fileName] = new DLLoader<IDisplayModule>("lib/" + fileName);
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
                games[fileName] = new DLLoader<IGameModule>("games/" + fileName);
                std::cout << "create game loader for " + fileName << std::endl;
            }
        }
    }
}

IDisplayModule *Arcade::changeDisplay(const std::string &name)
{
    this->display->stop();
    this->display = this->libraries[name]->getInstance();
    this->display->init();
    return this->display;
}

IGameModule *Arcade::changeGame(const std::string &name)
{
    this->game->stop();
    this->game = this->games[name]->getInstance();
    this->game->init();
    return this->game;
}

IGameModule *Arcade::goToMainMenu()
{
    if (this->game != this->mainMenu) {
        this->game->stop();
        this->game = this->mainMenu;
        this->mainMenu->init();
    }
    return this->mainMenu;
}