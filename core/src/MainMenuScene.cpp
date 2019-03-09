/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** MainMenuScene.cpp
*/

#include "MainMenuScene.hpp"
#include "Sprites.hpp"

MainMenuScene::MainMenuScene()
: Scene("MainMenuScene", sprite_empty)
{
    this->addObject("test", form);
    objects["test"]->getMovement().setfreeMoving(true);
}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::manageEvents(IDisplayModule *display, std::map<Input, bool> &inputs)
{
    Object::MovementComponent &test = objects["test"]->getMovement();
    if (inputs[Input::ESCAPE_KEY] == true)
        display->stop();
    if (inputs[Input::Z_KEY] == true || inputs[Input::Q_KEY] == true || 
    inputs[Input::S_KEY] == true || inputs[Input::D_KEY] == true) {
        if (inputs[Input::Z_KEY] == true)
            test.setSpeed(test.getSpeed().first, -1);
        else if (inputs[Input::S_KEY] == true)
            test.setSpeed(test.getSpeed().first, 1);
        else
            test.setSpeed(test.getSpeed().first, 0);
        if (inputs[Input::Q_KEY] == true)
            test.setSpeed(-1, test.getSpeed().second);
        else if (inputs[Input::D_KEY] == true)
            test.setSpeed(1, test.getSpeed().second);
        else
            test.setSpeed(0, test.getSpeed().second);
    } else {
        test.setSpeed(0, 0);
    }
    
}