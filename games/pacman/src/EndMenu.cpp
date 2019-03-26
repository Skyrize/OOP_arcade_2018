/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** EndMenu
*/

#include "EndMenu.hpp"
#include "PacmanSprites.hpp"
#include "Text.hpp"

EndMenu::EndMenu(int score)
: Scene("EndMenu", none)
{
    Object *rightPacMan = this->addObject("PacmanRight", RightBigPacMan, {88, 30});
    Object *leftPacMan = this->addObject("PacmanLeft", LeftBigPacMan, {3, 30});

    this->addObject(new Text("PacmanTitle", "PacMan", 100, YELLOW, none, {35, 6}));
    this->addObject(new Text("PacmanLose", "You Lost", 80, WHITE, none, {35, 25}));
    this->addObject(new Text("PacmanEndScore", "Score : " + std::to_string(score), 80, WHITE, none, {34, 32}));
    this->addObject(new Text("PacmanEndInfo", "Press Enter to Restart", 70, WHITE, none, {13, 42}));
    rightPacMan->getAnimation().setLoop(true);
    rightPacMan->getAnimation().setAnimationSpeed(0.1);
    leftPacMan->getAnimation().setLoop(true);
    leftPacMan->getAnimation().setAnimationSpeed(0.1);
}

EndMenu::~EndMenu()
{
}
