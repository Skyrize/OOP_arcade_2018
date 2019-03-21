/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** MovementComponent.cpp
*/

#include "Object.hpp"
#include <iostream>

Object::MovementComponent::MovementComponent(Object &parent)
: parent(parent)
{
}

/*
bool Object::MovementComponent::willColide(float delta, Object *other) const
{
    if (this->blocking == false || other->getMovement().isBlocking() == false || &parent == other)
        return false;
    const std::pair<float, float> newPos{POS_X + SPEED_X * delta, POS_Y + SPEED_Y * delta};
    const std::pair<float, float> &thisSize = parent.sprite.getSize();
    const std::pair<float, float> &otherPos = other->getMovement().getPosition();
    const std::pair<float, float> &otherSize = other->sprite.getSize();

    //std::cout << this->parent.getName() << " is blocking " << other->getName() << std::endl;
    //std::cout << "actualPos = " << GET_X(position) << ", " << GET_Y(position) << std::endl;
    //std::cout << "newpos = " << GET_X(newPos) << ", " << GET_Y(newPos) << std::endl;
    //std::cout << "thisSize = " << GET_X(thisSize) << ", " << GET_Y(thisSize) << std::endl;
    //std::cout << other->getName() << "otherPos = " << GET_X(otherPos) << ", " << GET_Y(otherPos) << std::endl;
    //std::cout << "otherSize = " << GET_X(otherSize) << ", " << GET_Y(otherSize) << std::endl << std::endl;
    if ((int)GET_X(newPos) < (int)GET_X(otherPos) + (int)GET_X(otherSize) &&
    (int)GET_X(newPos) + (int)GET_X(thisSize) > (int)GET_X(otherPos) &&
    (int)GET_Y(newPos) < (int)GET_Y(otherPos) + (int)GET_Y(otherSize) &&
    (int)GET_Y(newPos) + (int)GET_Y(thisSize) > (int)GET_Y(otherPos)) {
        return true;
    }
    //std::cout << this->parent.getName() << " doesn't collide " << other->getName() << std::endl<< std::endl;
    return false;
} */

bool Object::MovementComponent::willColide(float delta, Object *other) const
{
    if (&parent == other) {
        return false;
    }
    const std::pair<float, float> newPos{POS_X + SPEED_X * delta, POS_Y + SPEED_Y * delta};
    const Sprite &mySprite = parent.sprite.getSprite();
    const std::pair<float, float> &otherPos = other->getMovement().getPosition();
    const Sprite &otherSprite = other->sprite.getSprite();

    //std::cout << this->parent.getName() << " is blocking " << other->getName() << std::endl;
    //std::cout << "actualPos = " << GET_X(position) << ", " << GET_Y(position) << std::endl;
    //std::cout << "newpos = " << GET_X(newPos) << ", " << GET_Y(newPos) << std::endl;
    //std::cout << "thisSize = " << GET_X(thisSize) << ", " << GET_Y(thisSize) << std::endl;
    //std::cout << other->getName() << "otherPos = " << GET_X(otherPos) << ", " << GET_Y(otherPos) << std::endl;
    //std::cout << "otherSize = " << GET_X(otherSize) << ", " << GET_Y(otherSize) << std::endl << std::endl;
    for (size_t y = 0; y != mySprite.size(); y++) {
        for (size_t x = 0; x != mySprite[y].size(); x++) {
            if (mySprite[y][x] != NONE) {
                for (size_t i = 0; i != otherSprite.size(); i++) {
                    for (size_t j = 0; j != otherSprite[i].size(); j++) {
                        if (otherSprite[i][j] != NONE &&
                        (int)GET_X(newPos) + x < (int)GET_X(otherPos) + j + 1 &&
                        (int)GET_X(newPos) + x + 1 > (int)GET_X(otherPos) + j &&
                        (int)GET_Y(newPos) + y < (int)GET_Y(otherPos) + i + 1 &&
                        (int)GET_Y(newPos) + y + 1 > (int)GET_Y(otherPos) + i) {
                            //std::cout << this->parent.getName() << " collide " << other->getName() << std::endl<< std::endl;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void Object::MovementComponent::move(const float &delta, std::map<std::string, Object *> &objects)
{
	std::pair<float, float> newPos{POS_X + SPEED_X * delta, POS_Y + SPEED_Y * delta};
    bool collide = false;
    //if (parent.getName() == "test") {
    //    std::cout << "prevpos = " << this->position.first << ", " << position.second << " |||| newpos = " << newPos.first << ", " << newPos.second << std::endl;
    //    std::cout << "delta = " << delta << std::endl;
    //    std::cout << "speed = " << SPEED_X << ", " << SPEED_Y << std::endl << std::endl;
    //}
	//std::pair<float, float> oldPos = this->position;
	//float tmpX = 0;
	//float tmpY = 0;
	//int blocks = (newPos.first - oldPos.first) + (newPos.second - oldPos.second);
	//for (int i = 1; i != 16 * blocks; i++) {
	//	tmpX = lerp(oldPos.first, newPos.first, i / 16 * blocks);
	//	tmpY = lerp(oldPos.second, newPos.second, i / 16 * blocks);
	//}

    if (isMoving() == true) {
        //std::cout << parent.getName() << " try to move" << std::endl;
        for (auto &e : objects)
            if (e.second)
                if (this->willColide(delta, e.second) == true) {

                    if (isBlocking() == true) {
                        collide = true;
                    }
                    parent.hitEvent(e.second);
            }
        if (collide == false)
            setPosition(GET_X(newPos), GET_Y(newPos));
        // else
            // std::cout << parent.getName() << " is blocked" << std::endl;

        if (freeMoving == false)
            if (hasReachDuration(delta) == true) {
                setSpeed(0, 0);

            }
    }
    //std::cout << parent.getName() << " has speed " << SPEED_X << ", " << SPEED_Y << std::endl;
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
	return (SPEED_X != 0 || SPEED_Y != 0);
}

bool Object::MovementComponent::isFreeMoving() const
{
	return freeMoving;
}

bool Object::MovementComponent::isBlocking() const
{
	return blocking;
}


void Object::MovementComponent::setFreeMoving(const bool &state)
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
    SPEED_Y = (GET_Y(newDest) - POS_Y) / timeToReach;
    DEST_X = GET_X(newDest);
    DEST_Y = GET_Y(newDest);
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
