/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Object.cpp
*/

#include "Object.hpp"
#include <iostream>

Object::Object(const std::string &name, std::vector<std::vector<Color> > &sprite, std::pair<float, float> position)
: name(name), sprite(sprite), movement(*this)
{
	this->movement.setPosition(position.first, position.second);
}

void Object::display(IDisplayModule *display)
{
	const std::pair<float, float> &position = this->movement.getPosition();
	display->drawShape(std::get<0>(position), std::get<1>(position), sprite);
}

void Object::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
	movement.move(display->getTime(), objects);
}

void Object::manageEvents(IDisplayModule *display, std::map<Input, bool> &inputs)
{
	(void)display;
	(void)inputs;
}

Object::MovementComponent &Object::getMovement()
{
	return this->movement;
}

const std::vector<std::vector<Color> > &Object::getSprite() const
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

void Object::MovementComponent::move(float actualTime, std::map<std::string, Object *> &objects)
{
    static float prevTime = 0;
    float delta = actualTime - prevTime;

    //std::cout << "prevtime = " << prevTime << " actual = " << actualTime << "delta = " << delta << std::endl;
	std::pair<float, float> newPos{POS_X + SPEED_X * delta * 32, POS_Y + SPEED_Y * delta * 32};
    //std::cout << "prevpos = " << this->position.first << ", " << position.second << " |||| newpos = " << newPos.first << ", " << newPos.second << std::endl;
	//std::pair<float, float> oldPos = this->position;
	//float tmpX = 0;
	//float tmpY = 0;
	//int blocks = (newPos.first - oldPos.first) + (newPos.second - oldPos.second);
	(void)objects;
	//for (int i = 1; i != 32 * blocks; i++) {
	//	tmpX = lerp(oldPos.first, newPos.first, i / 32 * blocks);
	//	tmpY = lerp(oldPos.second, newPos.second, i / 32 * blocks);
	//}
    setPosition(GET_X(newPos), GET_Y(newPos));

	
    if (freeMoving == false)
        if (hasReachDuration(delta) == true)
            setSpeed(0, 0);
    prevTime = actualTime;
}

bool Object::MovementComponent::hasReachDuration(float delta)
{
    remainingTimeMoving -= delta;
    if (remainingTimeMoving <= 0)  {
        remainingTimeMoving = 0;
        POS_X = DEST_X;
        POS_Y = DEST_Y;
        return true;
    }
    return false;
}

void Object::MovementComponent::setSpeed(const float &x, const float &y)
{
    SPEED_X = x;
    SPEED_Y = y;
}

void Object::MovementComponent::setPosition(const float &x, const float &y)
{
    POS_X = x;
    POS_Y = y;
}

bool Object::MovementComponent::isMoving() const
{
	return this->speed.first != 0 || this->speed.second != 0;
}

bool Object::MovementComponent::isFreeMoving() const
{
	return freeMoving;
}

bool Object::MovementComponent::isBlocking() const
{
	return blocking;
}


void Object::MovementComponent::setfreeMoving(const bool &state)
{
    freeMoving = state;
}

void Object::MovementComponent::setBlocking(const bool &state)
{
    blocking = state;
}

void Object::MovementComponent::setDestination(const std::pair<float, float> &newDest, const float &timeToReach)
{
    remainingTimeMoving = timeToReach;
    SPEED_X = (GET_X(newDest) - POS_X) / timeToReach;
    SPEED_X = (GET_Y(newDest) - POS_Y) / timeToReach;
    freeMoving = false;
}

const std::pair<float, float> &Object::MovementComponent::getPosition() const
{
	return this->position;
}

const std::pair<float, float> &Object::MovementComponent::getSpeed() const
{
	return this->speed;
}

const std::pair<float, float> &Object::MovementComponent::getDestination() const
{
	return this->destination;
}
