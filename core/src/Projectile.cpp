/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Projectile
*/

#include "Projectile.hpp"
#include <iostream>

SpriteSheet projectileSpriteSheet {
    {
        {RED},
        {RED}
    },
    {
        {YELLOW},
        {YELLOW}
    }
};

Projectile::Projectile(Invader &parent, const std::pair<float, float> &speed, const std::pair<float, float> &position)
: Object("Bullet-" + parent.getName() + std::to_string(getId()), projectileSpriteSheet, position), parent(parent), space(parent.getParent())
{
    this->lifetime = parent.getGun().getLifeTime();
    this->damages = parent.getGun().getDamages();
    std::pair<float, float> dest{movement.getPosition().first + lifetime * GET_X(speed) * parent.getGun().getAmmoSpeed(), movement.getPosition().second + lifetime * GET_Y(speed) * parent.getGun().getAmmoSpeed()};

    sprite.setAnimationSpeed(0.2);
    sprite.setLoop(true);
    movement.setBlocking(true);
    this->movement.setDestination(dest, lifetime);

}

Projectile::~Projectile()
{
}

int Projectile::getId()
{
    static int id = 0;

    return id++;
}

float Projectile::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float delta = Object::update(display, objects);
    
    this->lifetime -= delta;
    if (lifetime <= 0) {
        space.removeObject(this->name);
    }
    return delta;
}

void Projectile::eventHit(Object *other)
{
    other->eventHit(this);
    space.removeObject(name);
}