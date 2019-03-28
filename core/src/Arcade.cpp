/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Arcade.cpp
*/

#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Arcade.hpp"

Arcade::Arcade(char *baseDisplayModule)
{
    std::string bdmString(baseDisplayModule);
    int hasFind = -1;

    loadLibraries();
    loadGames();
    loadHighScores();
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

void Arcade::loadHighScores()
{
    DIR *dir = opendir("highscores/");
    struct dirent *file;
    std::ifstream fileStream;
    std::string line;
    std::string fileName;

    if (!dir) {
        std::cerr << "Cannot open HighScores directory !" << std::endl;
    } else {
        while ((file = readdir(dir)) != NULL) {
            fileName = std::string(file->d_name);
            if (fileName.find(".txt") == std::string::npos)
                continue;
            fileStream.open("highscores/" + fileName, std::ifstream::in);
            while (std::getline(fileStream, line)) {
                if (line == "")
                    break;
                else
                    highScores[fileName.substr(0, fileName.find(".txt"))][line.substr(0, 3)] = atoi(line.substr(3).c_str());
            }
            fileStream.close();
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
    this->inputs = this->display->catchInput();
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
    }
    if (inputs[ESCAPE_KEY] == true) {
        this->display->stop();
    }
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

static int getHighScoreOfGame(std::string gameName, std::map<std::string, std::map<std::string, int> > highScores)
{
    int highScore = 0;

    for (auto &i: highScores[gameName]) {
        if (i.second > highScore)
            highScore = i.second;
    }
    return highScore;
}

static const std::string getPlayerHighScore(std::string gameName, std::map<std::string, std::map<std::string, int> > highScores)
{
    int highScore = 0;
    std::string name;

    for (auto &i: highScores[gameName]) {
        if (i.second > highScore) {
            name = i.first;
            highScore = i.second;
        }
    }
    return name;
}

IGameModule *Arcade::changeGame(const size_t &index)
{
    this->display->restartTime();
    if (this->games.size() == 0) {
        return goToMainMenu();
    }
    if (this->game) {
        if (this->game->getName() != "MainMenu" && this->game->getHighScore())
            this->saveScore();
        this->game->stop();
        delete(game);
    }
    this->games[index]->init();
    this->game = this->games[index]->getInstance();
    this->game->init(getPlayerHighScore(this->game->getName(), highScores),
        getHighScoreOfGame(this->game->getName(), highScores));
    this->actualGame = index;
    return this->game;
}

IGameModule *Arcade::goToMainMenu()
{
    if (this->game->getName() == "MainMenu")
        return this->game;
    this->display->restartTime();
    if (this->game->getName() != "MainMenu" && this->game->getHighScore())
        this->saveScore();
    this->game->stop();
    delete(this->game);
    this->game = new MenuModule();
    this->game->init(getPlayerHighScore(this->game->getName(), highScores),
        getHighScoreOfGame(this->game->getName(), highScores));
    return this->game;
}

void Arcade::saveScore()
{
    std::ofstream fileStream("highscores/" + this->game->getName() + ".txt",
        std::ios_base::app | std::ios_base::out);
    
    this->highScores[this->game->getName()][this->playerName] = this->game->getHighScore();
    fileStream << this->playerName << this->game->getHighScore() << std::endl;
}