/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** MainMenuScene.cpp
*/

#include "MainMenuScene.hpp"
#include "Sprites.hpp"
#include <iostream>

MainMenuScene::MainMenuScene()
: Scene("MainMenuScene", sprite_empty)
{
    Object *test = this->addObject("test", sheet);
    test->getAnimation().setNbLoop(3);
    test->getAnimation().setAnimationSpeed(0.5);
    test->getMovement().setfreeMoving(true);
    test->getMovement().setBlocking(true);

    Object *test2 = this->addObject("test2", form, std::pair<float, float>{2.0, 10.0});
    test2->getMovement().setBlocking(true);
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
    inputs[Input::S_KEY] == true || inputs[Input::D_KEY] == true ||
    inputs[Input::UP_ARROW_KEY] == true || inputs[Input::LEFT_ARROW_KEY] == true || 
    inputs[Input::DOWN_ARROW_KEY] == true || inputs[Input::RIGHT_ARROW_KEY] == true) {
        if (inputs[Input::Z_KEY] == true || inputs[Input::UP_ARROW_KEY] == true)
            test.setSpeed(test.getSpeed().first, -40);
        else if (inputs[Input::S_KEY] == true || inputs[Input::DOWN_ARROW_KEY] == true)
            test.setSpeed(test.getSpeed().first, 40);
        else
            test.setSpeed(test.getSpeed().first, 0);
        if (inputs[Input::Q_KEY] == true || inputs[Input::LEFT_ARROW_KEY] == true)
            test.setSpeed(-40, test.getSpeed().second);
        else if (inputs[Input::D_KEY] == true || inputs[Input::RIGHT_ARROW_KEY] == true)
            test.setSpeed(40, test.getSpeed().second);
        else
            test.setSpeed(0, test.getSpeed().second);
    } else {
        test.setSpeed(0, 0);
    }
    
}