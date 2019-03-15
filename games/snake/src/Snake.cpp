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
    movement.setPosition(47, 37);

}

Snake::~Snake()
{
}

void Snake::eatFruit()
{

}

void Snake::addPart()
{
    if (parts.size() > 0) {

    } else {
        parts.push_back(new SnakePart(*this, nullptr, std::pair<float, float>{0, 0}));
    }
}

void Snake::moveParts()
{
}

size_t Snake::getNbParts()
{
    return parts.size();
}

bool Snake::fullyInBlock()
{
    const std::pair<float, float> &pos = movement.getPosition();

    if ((int)(GET_X(pos) + 1) % 3 == 0 && (int)(GET_Y(pos) - 1) % 3 == 0)
        return true;
    return false;
}

void Snake::replaceInBlock()
{
    const std::pair<float, float> &pos = movement.getPosition();
    int xOffset = (int)(GET_X(pos) + 1) % 3;
    int yOffset = (int)(GET_Y(pos) - 1) % 3;
    std::pair<float, float> newPos{GET_X(pos) - xOffset, GET_Y(pos) - yOffset};

    std::cout << xOffset << ", " << yOffset << std::endl;
    std::cout << "new pos = " << GET_X(newPos) << ", " << GET_Y(newPos) << std::endl << std::endl;
    switch (actualDirection)
    {
        case SPRITE_UP:
            movement.setPosition(GET_X(pos), GET_Y(pos));
            break;
        case SPRITE_DOWN:
            movement.setPosition(GET_X(pos), GET_Y(pos) + 3);
            break;
        case SPRITE_LEFT:
            movement.setPosition(GET_X(pos), GET_Y(pos));
            break;
        case SPRITE_RIGHT:
            movement.setPosition(GET_X(pos) + 3, GET_Y(pos));
            break;
        default:
            break;
    }
}

void Snake::up()
{
    if (actualDirection == SPRITE_DOWN)
        return;
    movement.setSpeed(0, -speed);
    sprite.goToSprite(SPRITE_UP);
    actualDirection = SPRITE_UP;
    if (fullyInBlock() == false)
        replaceInBlock();
}

void Snake::down()
{
    if (actualDirection == SPRITE_UP)
        return;
    movement.setSpeed(0, speed);
    sprite.goToSprite(SPRITE_DOWN);
    actualDirection = SPRITE_DOWN;
    if (fullyInBlock() == false)
        replaceInBlock();
}

void Snake::left()
{
    if (actualDirection == SPRITE_RIGHT)
        return;
    movement.setSpeed(-speed, 0);
    sprite.goToSprite(SPRITE_LEFT);
    actualDirection = SPRITE_LEFT;
    if (fullyInBlock() == false)
        replaceInBlock();
}

void Snake::right()
{
    if (actualDirection == SPRITE_LEFT)
        return;
    movement.setSpeed(speed, 0);
    sprite.goToSprite(SPRITE_RIGHT);
    actualDirection = SPRITE_RIGHT;
    if (fullyInBlock() == false) {
        std::cout << "false right" << std::endl;
        replaceInBlock();
    }
}

void Snake::manageEvents(std::map<Input, bool> &inputs)
{
    if (inputs[Input::UP_ARROW_KEY] == true) {
        up();
    } else if (inputs[Input::DOWN_ARROW_KEY] == true) {
        down();
    } else if (inputs[Input::LEFT_ARROW_KEY] == true) {
        left();
    } else if (inputs[Input::RIGHT_ARROW_KEY] == true) {
        right();
    }
}
