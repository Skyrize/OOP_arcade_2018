/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Arcade.cpp
*/

#include <sys/types.h>
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
    this->game = new MenuModule(*this);
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
        exit(84);
    } else {
        while ((file = readdir(dir)) != NULL) {
            std::string fileName(file->d_name);
            if (fileName.find(".so") != std::string::npos) {
                libraries.push_back(new DLLoader<IDisplayModule>("lib/" + fileName));
                //std::cout << "create lib loader for " + fileName << std::endl;
            }
        }
    }
    closedir(dir);
}

void Arcade::loadGames()
{
    DIR *dir = opendir("games/");
    struct dirent *file;

    if (!dir) {
        std::cout << "Cannot open games/ directory !" << std::endl;
        exit(84);
    } else {
        while ((file = readdir(dir)) != NULL) {
            std::string fileName(file->d_name);
            if (fileName.find(".so") != std::string::npos) {
                games.push_back(new DLLoader<IGameModule>("games/" + fileName));
                //std::cout << "create game loader for " + fileName << std::endl;
            }
        }
    }
    closedir(dir);
}

void Arcade::loadHighScores()
{
    DIR *dir = opendir("highscores/");
    struct dirent *file;
    std::ifstream fileStream;
    std::string line;
    std::string fileName;
    std::vector<std::pair<std::string, int>> vec;

    highScores.clear();
    if (!dir) {
        std::cerr << "Cannot open HighScores directory !" << std::endl;
        exit(84);
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
                    vec.push_back({line.substr(0, 3), atoi(line.substr(3).c_str())});
            }
            highScores.push_back({fileName.substr(0, fileName.find(".txt")), vec});
            vec.clear();
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
    if (inputs[ONE_KEY] == true ||
    inputs[TWO_KEY] == true ||
    inputs[THREE_KEY] == true ||
    inputs[FOUR_KEY] == true ||
    inputs[M_KEY] == true) {
        if (inputs[THREE_KEY] == true) {
            prevGame();
        } else if (inputs[FOUR_KEY] == true) {
            nextGame();
        } else if (inputs[M_KEY] == true) {
            goToMainMenu();
        }
        if (inputs[ONE_KEY] == true) {
            prevDisplay();
        } else if (inputs[TWO_KEY] == true) {
            nextDisplay();
        }
    }
    if (inputs[ESCAPE_KEY] == true) {
        if (this->game->getName() != "MainMenu" && this->game->getHighScore())
            this->saveScore();
        this->game->stop();
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

static std::pair<std::string, int> getHighScoreOfGame(std::string gameName,
    std::vector< std::pair< std::string, std::vector< std::pair< std::string, int > > > > highScores)
{
    std::pair<std::string, int> highScore = {"", 0};
    std::vector<std::pair<std::string, int>> gameHighScores;

    for (auto &i: highScores) {
        if (i.first == gameName) {
            gameHighScores = i.second;
            break;
        }
    }
    for (auto &i: gameHighScores) {
        if (i.second > highScore.second) {
            highScore.first = i.first;
            highScore.second = i.second;
        }
    }
    return highScore;
}

IGameModule *Arcade::changeGame(const size_t &index)
{
    std::pair<std::string, int> pair;

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
    pair = getHighScoreOfGame(this->game->getName(), highScores);
    this->game->init(pair.first, pair.second);
    this->actualGame = index;
    return this->game;
}

IGameModule *Arcade::goToMainMenu()
{
    std::pair<std::string, int> pair;

    if (this->game->getName() == "MainMenu")
        return this->game;
    this->display->restartTime();
    if (this->game->getName() != "MainMenu" && this->game->getHighScore())
        this->saveScore();
    this->game->stop();
    delete(this->game);
    this->game = new MenuModule(*this);
    pair = getHighScoreOfGame(this->game->getName(), highScores);
    this->game->init(pair.first, pair.second);
    return this->game;
}

void Arcade::saveScore()
{
    std::ofstream fileStream("highscores/" + this->game->getName() + ".txt",
        std::ios_base::app | std::ios_base::out);
    
    fileStream << this->playerName << this->game->getHighScore() << std::endl;
    loadHighScores();
}

std::string &Arcade::getPlayerName()
{
    return playerName;
}

const std::vector< std::pair< std::string, std::vector< std::pair< std::string, int > > > > &Arcade::getHighScores()
{
    return this->highScores;
}
std::vector<std::string> Arcade::getGameNames()
{
    std::vector<std::string> names;

    for (auto &e : this->games) {
        names.push_back(e->getFileName().substr(17, e->getFileName().size() - 20));
    }
    return names;
}

std::vector<std::string> Arcade::getLibNames()
{
    std::vector<std::string> names;

    for (auto &e : this->libraries) {
        names.push_back(e->getFileName().substr(15, e->getFileName().size() - 18));
    }
    return names;

}

size_t &Arcade::getActualGame()
{
    return actualGame;
}

size_t &Arcade::getActualLib()
{
    return actualLib;
}
