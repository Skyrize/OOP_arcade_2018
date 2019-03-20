/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ghost
*/

#include "Ghost.hpp"

Ghost::Ghost(const std::string &name, Sprite sprite, Scene *parent, const std::pair<float, float> &position) : Object(name, sprite, position), _parent(parent)
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

    if (map[pos.second - 3][pos.first] == BLUE)
        return 1;
    movement.setSpeed(0, -_speed);
    return 0;
}

int Ghost::down()
{
    std::pair<int, int> pos = std::pair<int, int>(movement.getPosition());
    Sprite map = this->_parent->getObject("PacmanMap")->getAnimation().getSprite();

    if (map[pos.second + 3][pos.first] == BLUE)
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
    std::cout << "test" << std::endl;
    (void)other;
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

float Ghost::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float delta = Object::update(display, objects);
    int direction = 0;

    if (int(this->movement.getPosition().first) % 3 != 0
    || int(this->movement.getPosition().second) % 3 != 0)
        return delta;
    direction = rand() % 4;
    for (int i = 0; i < 4; i++) {
        if (!callDirectionHandler(direction))
            break;
        direction++;
        if (direction == 4)
            direction = 0;
    }
    return delta;
}
