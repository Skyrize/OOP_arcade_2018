/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Object.cpp
*/

#include "Object.hpp"
#include <iostream>

Object::Object(const std::string &name, SpriteSheet &spriteSheet, std::pair<float, float> position)
: name(name), sprite(*this, spriteSheet), movement(*this)
{
	this->movement.setPosition(position.first, position.second);
}

Object::Object(const std::string &name, Sprite &sprite, std::pair<float, float> position)
: name(name), sprite(*this, sprite), movement(*this)
{
	this->movement.setPosition(position.first, position.second);
}

void Object::display(IDisplayModule *display)
{
	const std::pair<float, float> &position = this->movement.getPosition();

	display->drawShape(GET_X(position), GET_Y(position), sprite.getSprite());
}

void Object::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float actualTime = display->getTime();
    float delta = actualTime - oldTime;
    
    //std::cout << this->name << " delta = " << delta << std::endl;
	movement.move(delta, objects);
    sprite.animate(delta);
    oldTime = actualTime;
	//std::cout << std::endl <<std::endl;
}

void Object::manageEvents(IDisplayModule *display, std::map<Input, bool> &inputs)
{
	(void)display;
	(void)inputs;
}

void Object::hitEvent(Object *other)
{
	(void)other;
}

Object::MovementComponent &Object::getMovement()
{
	return this->movement;
}

Object::AnimationComponent &Object::getAnimation()
{
	return sprite;
}

const std::string &Object::getName() const
{
	return this->name;
}

/*					MovementComponent					*/

// static float lerp(float a, float b, float fraction)
// {
// 	return (a * (1.0 - fraction) + b * fraction);
// }
