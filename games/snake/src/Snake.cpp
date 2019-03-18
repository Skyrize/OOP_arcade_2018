/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#include "Snake.hpp"

//Sprite snakeHeadSheet {
//    {
//        {NONE, GREEN, NONE},
//        {GREEN, GREEN, GREEN},
//        {GREEN, YELLOW, GREEN},
//    },
//    {
//        {GREEN,  YELLOW, GREEN},
//        {GREEN, GREEN, GREEN},
//        {NONE,  GREEN, NONE},
//    },
//    {
//        {GREEN,  GREEN, NONE},
//        {YELLOW, GREEN, GREEN},
//        {GREEN,  GREEN, NONE},
//    },
//    {
//        {NONE,  GREEN, GREEN},
//        {GREEN, GREEN, YELLOW},
//        {NONE,  GREEN, GREEN},
//    },
//};

#define SNAKE_UP 0
#define SNAKE_DOWN 1
#define SNAKE_RIGHT 2
#define SNAKE_LEFT 3

Sprite snakeHeadSprite {
    {YELLOW},
};

Sprite snakePartSprite {
    {GREEN},
};

Sprite snakeTailSprite {
    {CYAN},
};

Snake::Snake(SnakeScene &parent)
: Object("Snake", snakeHeadSprite),
parent(parent)
{
    this->movement.setfreeMoving(true);
    movement.setBlocking(true);
    movement.setPosition(47, 37);

    body.push_back(new Object("SnakePart-" + std::to_string(body.size()), snakePartSprite, std::pair<float, float>{47, 38}));
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
    body.push_back(new Object("SnakePart-" + std::to_string(body.size()), snakePartSprite, std::pair<float, float>{47, 39}));
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
    body.push_back(new Object("SnakePart-" + std::to_string(body.size()), snakePartSprite, std::pair<float, float>{47, 40}));
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
    body.push_back(new Object("SnakeTail" + std::to_string(body.size()), snakeTailSprite, std::pair<float, float>{47, 41}));
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
}

Snake::~Snake()
{
}

float Snake::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    oldPos = movement.getPosition();
    int x = oldPos.first;
    int y = oldPos.second;
    float delta = Object::update(display, objects);

    if (isDead == false) {
        if (x != (int)movement.getPosition().first || y != (int)movement.getPosition().second)
            moveParts();
    } else {
        die(delta);
    }
    return delta;
}

void Snake::hitEvent(Object *other)
{
    if (other->getName() == "Fruit") {
        eatFruit();
    } else {
        for (auto &e : body)
            if (other == e) {
                isDead = true;
                movement.setSpeed(0, 0);

            }
    }
}

void Snake::eatFruit()
{
    parent.eventFruitEaten();
    addPart();
}

void Snake::die(float delta)
{
    static float start = 0;

    start += delta;
    if (start >= 0.2) {
        if (body.size() != 0) {
            parent.removeObject(body[body.size() - 1]->getName());
            body.pop_back();
        } else {
            parent.removeObject(this->name);
        }
        start = 0;
    }
}

void Snake::addPart()
{
    Object *tail = body[body.size() - 1];
    
    body[body.size() - 1] = new Object("SnakePart-" + std::to_string(body.size()), snakePartSprite, std::pair<float, float>{0, 0});
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
    body.push_back(tail);
}

void Snake::moveParts()
{
    if (movement.isMoving() == false)
        return;
    for (int i = body.size() - 1; i != 0; i--) {
        body[i]->getMovement().setPosition(body[i - 1]->getMovement().getPosition().first, body[i - 1]->getMovement().getPosition().second);
    }
    body[0]->getMovement().setPosition(oldPos.first, oldPos.second);
}

size_t Snake::getNbParts()
{
    return body.size();
}

// bool Snake::fullyInBlock()
// {
//     const std::pair<float, float> &pos = movement.getPosition();

//     if ((int)(GET_X(pos) + 1) % 3 == 0 && (int)(GET_Y(pos) - 1) % 3 == 0)
//         return true;
//     return false;
// }

void Snake::up()
{
    if (actualDirection == SNAKE_DOWN)
        return;
    movement.setSpeed(0, -speed);
    actualDirection = SNAKE_UP;
}

void Snake::down()
{
    if (actualDirection == SNAKE_UP)
        return;
    movement.setSpeed(0, speed);
    actualDirection = SNAKE_DOWN;
}

void Snake::left()
{
    if (actualDirection == SNAKE_RIGHT)
        return;
    movement.setSpeed(-speed, 0);
    actualDirection = SNAKE_LEFT;
}

void Snake::right()
{
    if (actualDirection == SNAKE_LEFT)
        return;
    movement.setSpeed(speed, 0);
    actualDirection = SNAKE_RIGHT;
}

void Snake::manageEvents(std::map<Input, bool> &inputs)
{
    if (isDead == false) {
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
}
