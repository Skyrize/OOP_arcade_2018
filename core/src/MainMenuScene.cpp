/*
** EPITECH PROJECT, 2040
** OOP_arcade_2040
** File description:
** MainMenuScene.cpp
*/

#include "MainMenuScene.hpp"
#include "Sprites.hpp"
#include "Invader.hpp"
#include <iostream>

SpriteSheet none{{}};

MainMenuScene::MainMenuScene()
: Scene("MainMenuScene", none)
{
    addObject(new Invader(*this));
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::manageEvents(std::map<Input, bool> &inputs)
{
    this->objects["SpaceInvader"]->manageEvents(inputs);
}