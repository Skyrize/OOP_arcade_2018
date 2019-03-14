/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakeScene
*/

#include "SnakeScene.hpp"
#include "Snake.hpp"

static Sprite none {{}};

SnakeScene::SnakeScene()
: Scene("SnakeScene", none)
{
    this->addObject(new Snake);
}

SnakeScene::~SnakeScene()
{
}

void SnakeScene::manageEvents(std::map<Input, bool> &inputs)
{
    objects["Snake"]->manageEvents(inputs);
}
