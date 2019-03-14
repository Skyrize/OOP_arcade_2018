/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#include "Snake.hpp"

SpriteSheet snakeHeadSheet {
    {
        {NONE, GREEN, NONE},
        {GREEN, GREEN, GREEN},
        {GREEN, YELLOW, GREEN},
    },
    {
        {GREEN,  YELLOW, GREEN},
        {GREEN, GREEN, GREEN},
        {NONE,  GREEN, NONE},
    },
    {
        {GREEN,  GREEN, NONE},
        {YELLOW, GREEN, GREEN},
        {GREEN,  GREEN, NONE},
    },
    {
        {NONE,  GREEN, GREEN},
        {GREEN, GREEN, YELLOW},
        {NONE,  GREEN, GREEN},
    },
};

#define SPRITE_UP 0
#define SPRITE_DOWN 1
#define SPRITE_RIGHT 2
#define SPRITE_LEFT 3


Snake::Snake()
: Object("Snake", snakeHeadSheet)
{
    this->movement.setfreeMoving(true);
    movement.setBlocking(true);

    //this->parts.push_back(new SnakePart);
}

Snake::~Snake()
{
}

void Snake::manageEvents(std::map<Input, bool> &inputs)
{
    if (inputs[Input::UP_ARROW_KEY] == true || inputs[Input::LEFT_ARROW_KEY] == true || 
    inputs[Input::DOWN_ARROW_KEY] == true || inputs[Input::RIGHT_ARROW_KEY] == true) {
        if (inputs[Input::UP_ARROW_KEY] == true) {
            movement.setSpeed(movement.getSpeed().first, -100);
            sprite.goToSprite(SPRITE_UP);
        } else if (inputs[Input::DOWN_ARROW_KEY] == true) {
            movement.setSpeed(movement.getSpeed().first, 100);
            sprite.goToSprite(SPRITE_DOWN);
        } else
            movement.setSpeed(movement.getSpeed().first, 0);
        if (inputs[Input::LEFT_ARROW_KEY] == true) {
            movement.setSpeed(-100, movement.getSpeed().second);
            sprite.goToSprite(SPRITE_LEFT);
        } else if (inputs[Input::RIGHT_ARROW_KEY] == true) {
            movement.setSpeed(100, movement.getSpeed().second);
            sprite.goToSprite(SPRITE_RIGHT);
        } else
            movement.setSpeed(0, movement.getSpeed().second);
    } else {
        movement.setSpeed(0, 0);
    }
}
