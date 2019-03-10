/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** AnimationComponent.cpp
*/

#include "Object.hpp"

Object::AnimationComponent::AnimationComponent(Object &parent, SpriteSheet &spriteSheet)
: parent(parent), spriteSheet(spriteSheet)
{
    setSize();
}

Object::AnimationComponent::AnimationComponent(Object &parent, Sprite &sprite)
: parent(parent)
{
    spriteSheet.push_back(sprite);
    setSize();
}

void Object::AnimationComponent::animate(float delta)
{
    static float remainingTime = 0;

    if (isAnimated() == true) {
        if (remainingTime <= 0) {
            remainingTime = this->animationSpeed;
            goNextSprite();
        } else {
            remainingTime -= delta;
        }
    }
}

const Sprite &Object::AnimationComponent::getSprite() const
{
    return spriteSheet[actual];
}

const SpriteSheet &Object::AnimationComponent::getSpriteSheet() const
{
    return spriteSheet;
}

const std::pair<float, float> &Object::AnimationComponent::getSize() const
{
    return size;
}

bool Object::AnimationComponent::isAnimated() const
{
    return animationSpeed != 0 && (nbLoop != 0 || infiniteLoop == true);
}

void Object::AnimationComponent::setAnimationSpeed(const float &speed)
{
    animationSpeed = speed;
}

void Object::AnimationComponent::setNbLoop(const float &nbLoop)
{
    this->nbLoop = nbLoop;
}

void Object::AnimationComponent::setLoop(const bool &state)
{
    this->infiniteLoop = state;
}

void Object::AnimationComponent::goNextSprite()
{
    if (actual == spriteSheet.size() - 1) {
        if (infiniteLoop == false && nbLoop != 0)
            nbLoop--;
        actual = 0;
    } else {
        actual++;
    }
}


void Object::AnimationComponent::setSize()
{
    const Sprite &sprite = getSprite();
    float nbBlockY = sprite.size();
    float nbBlockX = 0;
    std::pair<float, float> size;
    
    for (auto &e : sprite)
        if (e.size() > nbBlockX)
            nbBlockX = e.size();
    this->size = {nbBlockX, nbBlockY};
}