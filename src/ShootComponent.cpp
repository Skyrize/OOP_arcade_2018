/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ShootComponent.cpp
*/

#include "Invader.hpp"
#include <iostream>

Invader::ShootComponent::ShootComponent(Invader &parent, const bool &infiniteAmmo, const float &ammoLifetime, const float &ammoSpeed, const float &fireRate, const float &reloadTime, const float &damages)
: parent(parent),
infiniteAmmo(infiniteAmmo),
maxAmmo(0),
actualAmmo(0),
ammoLifetime(ammoLifetime), 
ammoSpeed(ammoSpeed),
fireRate(fireRate),
reloadTime(reloadTime),
damages(damages)
{
}

Invader::ShootComponent::ShootComponent(Invader &parent, const float &maxAmmo, const float &ammoLifetime, const float &ammoSpeed, const float &fireRate, const float &reloadTime, const float &damages)
: parent(parent),
infiniteAmmo(false),
maxAmmo(maxAmmo),
actualAmmo(maxAmmo),
ammoLifetime(ammoLifetime), 
ammoSpeed(ammoSpeed),
fireRate(fireRate),
reloadTime(reloadTime),
damages(damages)
{
}

void Invader::ShootComponent::shoot(const std::pair<float, float> &speed)
{
    const std::pair<float, float> &parentPos = parent.getMovement().getPosition();
    const std::pair<float, float> newPos{parentPos.first + 2, parentPos.second - 2};

    if (this->fireTimer <= 0) {
        if (this->infiniteAmmo == true) {
            parent.getParent().addObject(new Projectile(parent, speed, newPos));
            this->fireTimer = fireRate;
            this->setHasShot(true);
        } else if (actualAmmo > 0) {
            parent.getParent().addObject(new Projectile(parent, speed, newPos));
            this->fireTimer = fireRate;
            actualAmmo--;
            this->setHasShot(true);
        }
    }
}

void Invader::ShootComponent::reload()
{

}

bool Invader::ShootComponent::hasInfiniteAmmo()
{
    return infiniteAmmo;
}

bool Invader::ShootComponent::hasShot()
{
    return hasFired;
}

void Invader::ShootComponent::setHasShot(const bool &state)
{
    this->hasFired = state;
}

int Invader::ShootComponent::getActualAmmo()
{
    return actualAmmo;
}

int Invader::ShootComponent::getMaxAmmo()
{
    return maxAmmo;
}

float Invader::ShootComponent::getFireRate()
{
    return fireRate;
}

float Invader::ShootComponent::getFireTimer()
{
    return fireTimer;
}

void Invader::ShootComponent::setFireTimer(const float &time)
{
    this->fireTimer = time;
}

float Invader::ShootComponent::getReloadTime()
{
    return reloadTime;
}

float Invader::ShootComponent::getDamages()
{
    return damages;
}

float Invader::ShootComponent::getLifeTime()
{
    return ammoLifetime;
}

float Invader::ShootComponent::getAmmoSpeed()
{
    return ammoSpeed;
}
