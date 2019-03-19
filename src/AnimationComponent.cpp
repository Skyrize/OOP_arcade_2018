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

const size_t &Object::AnimationComponent::getActual() const
{
    return actual;
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
    remainingTime = speed;
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
    setSize();
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

void Object::AnimationComponent::goToSprite(const size_t &index)
{
    if (index < spriteSheet.size()) {
        actual = index;
        setSize();
    }
}

void Object::AnimationComponent::changeSpriteSheet(SpriteSheet &spriteSheet)
{
    this->spriteSheet = spriteSheet;
    actual = 0;
    remainingTime = animationSpeed;
    setSize();
}

void Object::AnimationComponent::changeSpriteSheet(Sprite &sprite)
{
    SpriteSheet newSpriteSheet;

    newSpriteSheet.push_back(sprite);
    this->spriteSheet = newSpriteSheet;
    actual = 0;
    remainingTime = animationSpeed;
    setSize();

}