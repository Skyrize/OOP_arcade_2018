/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#include "Pacman.hpp"

SpriteSheet pacmanRightSheet {
    {
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
    },
    {
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, NONE},
        {YELLOW, YELLOW, YELLOW},
    },
};

SpriteSheet pacmanDownSheet {
    {
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
    },
    {
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, NONE, YELLOW},
    },
};

SpriteSheet pacmanLeftSheet {
    {
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
    },
    {
        {YELLOW, YELLOW, YELLOW},
        {NONE, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
    },
};

SpriteSheet pacmanUpSheet {
    {
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
    },
    {
        {YELLOW, NONE, YELLOW},
        {YELLOW, YELLOW, YELLOW},
        {YELLOW, YELLOW, YELLOW},
    },
};


Pacman::Pacman(Scene *scene)
: Object("Pacman", pacmanRightSheet, {6.0, 3.0}), scene(scene)
{
    this->movement.setfreeMoving(true);
    this->sprite.setLoop(true);
    this->sprite.setAnimationSpeed(0.3);
    this->movement.setBlocking(true);
}

Pacman::~Pacman()
{
}

void Pacman::up()
{
    size_t prevPosition = sprite.getActual();
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->scene->getObject("PacmanMap")->getAnimation().getSprite();

    this->buffer = UP;
    if (pos.first % 3 != 0 || map[pos.second - 3][pos.first] == BLUE)
        return;
    this->buffer = NONE;
    movement.setSpeed(0, -_speed);
    if (sprite.getSpriteSheet() != pacmanUpSheet)
        sprite.changeSpriteSheet(pacmanUpSheet);
    sprite.goToSprite(prevPosition);
}

void Pacman::down()
{
    size_t prevPosition = sprite.getActual();
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->scene->getObject("PacmanMap")->getAnimation().getSprite();

    this->buffer = DOWN;
    if (pos.first % 3 != 0 || map[pos.second + 3][pos.first] == BLUE)
        return;
    this->buffer = NONE;
    movement.setSpeed(0, _speed);
    if (sprite.getSpriteSheet() != pacmanDownSheet)
        sprite.changeSpriteSheet(pacmanDownSheet);
    sprite.goToSprite(prevPosition);
}

void Pacman::left()
{
    size_t prevPosition = sprite.getActual();
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->scene->getObject("PacmanMap")->getAnimation().getSprite();

    this->buffer = LEFT;
    if (pos.second % 3 != 0 || map[pos.second][pos.first - 3] == BLUE)
        return;
    this->buffer = NONE;
    movement.setSpeed(-_speed, 0);
    if (sprite.getSpriteSheet() != pacmanLeftSheet)
        sprite.changeSpriteSheet(pacmanLeftSheet);
    sprite.goToSprite(prevPosition);
}

void Pacman::right()
{
    size_t prevPosition = sprite.getActual();
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->scene->getObject("PacmanMap")->getAnimation().getSprite();

    this->buffer = RIGHT;
    if (pos.second % 3 != 0 || map[pos.second][pos.first + 3] == BLUE)
        return;
    this->buffer = NONE;
    movement.setSpeed(_speed, 0);
    if (sprite.getSpriteSheet() != pacmanRightSheet)
        sprite.changeSpriteSheet(pacmanRightSheet);
    sprite.goToSprite(prevPosition);
}

void Pacman::manageEvents(std::map<Input, bool> &inputs)
{
    if (inputs[Input::UP_ARROW_KEY])
        up();
    else if (inputs[Input::DOWN_ARROW_KEY])
        down();
    else if (inputs[Input::LEFT_ARROW_KEY])
        left();
    else if (inputs[Input::RIGHT_ARROW_KEY])
        right();
    else if (buffer == UP)
        up();
    else if (buffer == DOWN)
        down();
    else if (buffer == LEFT)
        left();
    else if (buffer == RIGHT)
        right();
}

void Pacman::hitEvent(Object *other)
{
    other->hitEvent(this);
    return;
}

float Pacman::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float delta = Object::update(display, objects);

    return delta;
}