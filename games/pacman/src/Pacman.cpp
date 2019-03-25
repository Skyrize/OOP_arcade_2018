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

Pacman::Pacman(Scene *parent)
: Object("Pacman", pacmanRightSheet, {10.0 * 3, 15.0 * 3}), _parent(parent)
{
    this->movement.setFreeMoving(true);
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
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    this->_buffer = UP;
    if (pos.first % 3 != 0 || map[pos.second - 3][pos.first] == BLUE)
        return;
    this->_buffer = NONE;
    movement.setSpeed(0, -_speed);
    if (sprite.getSpriteSheet() != pacmanUpSheet)
        sprite.changeSpriteSheet(pacmanUpSheet);
    sprite.goToSprite(prevPosition);
}

void Pacman::down()
{
    size_t prevPosition = sprite.getActual();
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    this->_buffer = DOWN;
    if (pos.first % 3 != 0 || map[pos.second + 3][pos.first] == BLUE)
        return;
    this->_buffer = NONE;
    movement.setSpeed(0, _speed);
    if (sprite.getSpriteSheet() != pacmanDownSheet)
        sprite.changeSpriteSheet(pacmanDownSheet);
    sprite.goToSprite(prevPosition);
}

void Pacman::left()
{
    size_t prevPosition = sprite.getActual();
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    this->_buffer = LEFT;
    if (pos.second % 3 != 0 || map[pos.second][pos.first - 3] == BLUE)
        return;
    this->_buffer = NONE;
    movement.setSpeed(-_speed, 0);
    if (sprite.getSpriteSheet() != pacmanLeftSheet)
        sprite.changeSpriteSheet(pacmanLeftSheet);
    sprite.goToSprite(prevPosition);
}

void Pacman::right()
{
    size_t prevPosition = sprite.getActual();
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    this->_buffer = RIGHT;
    if (pos.second % 3 != 0 || map[pos.second][pos.first + 3] == BLUE)
        return;
    this->_buffer = NONE;
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
    else if (_buffer == UP)
        up();
    else if (_buffer == DOWN)
        down();
    else if (_buffer == LEFT)
        left();
    else if (_buffer == RIGHT)
        right();
}

void Pacman::eventHit(Object *other)
{
    if (other->getName().find("Teleporter", 0) != std::string::npos)
        other->eventHit(this);
    if (other->getName().find("Ghost") != std::string::npos) {
        if (_state == BEASTMODE && ((Ghost *)other)->isAlive()) {
            ((Ghost *)other)->kill();
            this->_beastMode.ghostKilled += 1;
            ((PacmanScene *)_parent)->addScore(200 * this->_beastMode.ghostKilled);
        } else if (_state != BEASTMODE) {
            this->_alive = false;
        }
    }
    if (other->getName().find("APacGum") == std::string::npos)
        return;
    if (other->getName().find("APacGum", 0) == 0)
        ((PacmanScene *)_parent)->addScore(10);
    else {
        ((PacmanScene *)_parent)->addScore(50);
        this->_state = BEASTMODE;
        this->_beastMode.lifeTime = 9;
        this->_beastMode.ghostKilled = 0;
        ((PacmanScene *)_parent)->affraidGhosts();
    }
    this->_parent->removeObject(other->getName());
}

float Pacman::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float delta = Object::update(display, objects);

    if (this->_state == BEASTMODE) {
        this->_beastMode.lifeTime -= delta;
        if (this->_beastMode.lifeTime <= 0) {
            this->_state = NORMAL;
            ((PacmanScene *)_parent)->unaffraidGhosts();
        }
    }
    return delta;
}