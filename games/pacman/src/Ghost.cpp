/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ghost
*/

#include "Ghost.hpp"

static SpriteSheet affraidSprite = {
    {
        {WHITE, BLUE, WHITE,},
        {BLUE, BLUE, BLUE,},
        {BLUE, NONE, BLUE,},
    },
    {
        {BLUE, WHITE, BLUE,},
        {WHITE, WHITE, WHITE,},
        {WHITE, NONE, WHITE,},
    },
};

static Sprite deadGhost = {
    {WHITE, NONE, WHITE,},  
    {BLACK, NONE, BLACK,},  
    {NONE, NONE, NONE,},  
};

Ghost::Ghost(const std::string &name, Sprite sprite, Scene *parent, const std::pair<float, float> &position) :
    Object(name, sprite, position), _parent(parent),
    _destination((std::pair<int, int>)position), _oldSprite(sprite)
{
    this->movement.setBlocking(false);
    this->movement.setFreeMoving(true);
    this->sprite.setLoop(true);
    this->sprite.setAnimationSpeed(0.3);
}

Ghost::~Ghost()
{
}

int Ghost::up()
{
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    if (map[pos.second - 3][pos.first] == BLUE
    || (_parent->getObject("Gate")
    &&_parent->getObject("Gate")->getMovement().getPosition().first == pos.first
    && _parent->getObject("Gate")->getMovement().getPosition().second == pos.second - 3))
        return 1;
    movement.setSpeed(0, -_speed);
    return 0;
}

int Ghost::down()
{
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    if (map[pos.second + 3][pos.first] == BLUE
    || (_parent->getObject("Gate")
    && _parent->getObject("Gate")->getMovement().getPosition().first == pos.first
    && _parent->getObject("Gate")->getMovement().getPosition().second == pos.second + 3))
        return 1;
    movement.setSpeed(0, _speed);
    return 0;
}

int Ghost::left()
{
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    if (map[pos.second][pos.first - 3] == BLUE)
        return 1;
    movement.setSpeed(-_speed, 0);
    return 0;
}

int Ghost::right()
{
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    if (map[pos.second][pos.first + 3] == BLUE)
        return 1;
    movement.setSpeed(_speed, 0);
    return 0;
}

void Ghost::hitEvent(Object *other)
{
    if (other->getName().find("Teleporter", 0) != std::string::npos) {
        other->hitEvent(this);
        if (movement.getPosition() == (std::pair<float, float>){61, 27})
            _destination = {60, 27};
        else
            _destination = {0, 27};
    }
}

int Ghost::callDirectionHandler(int direction)
{
    std::pair<int, int (Ghost::*)()> tab[4] = {
        {0, &Ghost::up},
        {1, &Ghost::down},
        {2, &Ghost::left},
        {3, &Ghost::right},
    };

    for (auto &i : tab) {
        if (i.first == direction) {
            if (!(this->*(i.second))())
                return 0;
            else
                return 1;
        }
    }
    return 1;
}

void Ghost::setDestination(direction_t direction)
{
    std::pair<int, int> actualPos = (std::pair<int, int>)this->movement.getPosition();

    switch (direction) {
        case UP:
            _destination.first = actualPos.first;
            _destination.second = actualPos.second - 3;
            _reverseDirection = DOWN;
            break;
        case DOWN:
            _destination.first = actualPos.first;
            _destination.second = actualPos.second + 3;
            _reverseDirection = UP;
            break;
        case LEFT:
            _destination.first = actualPos.first - 3;
            _destination.second = actualPos.second;
            _reverseDirection = RIGHT;
            break;
        case RIGHT:
            _destination.first = actualPos.first + 3;
            _destination.second = actualPos.second;
            _reverseDirection = LEFT;
            break;
        default:
            break;
    }
    _direction = (direction_t)direction;
}

void Ghost::kill()
{
    _alive = false;
    _destination = {10 * 3, 10 * 3};
    _oldSpeed = _speed;
    this->getAnimation().changeSpriteSheet(deadGhost);
    this->movement.setDestination({10 * 3, 10 * 3}, 3);
}

void Ghost::revive()
{
    _alive = true;
    _speed = _oldSpeed;
    ((PacmanScene *)this->_parent)->setNeedToOpen(true);
    this->getAnimation().changeSpriteSheet(_oldSprite);
    this->movement.setBlocking(false);
    this->movement.setFreeMoving(true);
    this->sprite.setLoop(true);
    this->sprite.setAnimationSpeed(0.3);
}

float Ghost::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float delta = Object::update(display, objects);
    std::pair<int, int> actualPos = (std::pair<int, int>)this->movement.getPosition();
    int direction = 0;

    if (!_alive && actualPos == _destination)
        revive();
    if (!_alive)
        return delta;
    if (actualPos.first % 3 != 0 || actualPos.second % 3 != 0
    || actualPos != _destination)
        return delta;
    direction = rand() % 4;
    for (int i = 0; i < 4; i++) {
        if (_reverseDirection != (direction_t)direction
        && !callDirectionHandler(direction))
            break;
        direction++;
        if (direction == 4)
            direction = 0;
        if (i == 3) {
            direction = _reverseDirection;
            callDirectionHandler(direction);
        }
    }
    setDestination((direction_t)direction);
    return delta;
}

void Ghost::affraid()
{
    this->setSpeed(_speed * 0.8);
    this->_state = AFFRAID;
    this->getAnimation().changeSpriteSheet(affraidSprite);
    this->getAnimation().setAnimationSpeed(0.5);
}

void Ghost::unaffraid()
{
    this->setSpeed(_speed / 0.8);
    this->_state = NORMAL;
    this->getAnimation().changeSpriteSheet(_oldSprite);
    this->getAnimation().setAnimationSpeed(0.3);
}