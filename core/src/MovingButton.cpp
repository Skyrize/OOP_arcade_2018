/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MovingButton
*/

#include "MovingButton.hpp"

MovingButton::MovingButton(MainMenuScene &parent, const int &targetPannelIndex, const int &startOffset, const int &endOffset, const std::string &name, SpriteSheet &spriteSheet, const std::pair<float, float> &position)
: Button(parent, targetPannelIndex, name, spriteSheet, position),
startOffset(startOffset),
endOffset(endOffset)
{
    std::pair<float, float> nextPos = {GET_X(position) + startOffset, GET_Y(position)};

    this->movement.setBlocking(true);
    basePosition = movement.getPosition();
    movement.setDestination(nextPos, 0.25);
}

MovingButton::MovingButton(MainMenuScene &parent, const int &targetPannelIndex, const int &startOffset, const int &endOffset, const std::string &name, Sprite &sprite, const std::pair<float, float> &position)
: Button(parent, targetPannelIndex, name, sprite, position),
startOffset(startOffset),
endOffset(endOffset)
{
    std::pair<float, float> nextPos = {GET_X(position) + startOffset, GET_Y(position)};

    this->movement.setBlocking(true);
    basePosition = movement.getPosition();
    movement.setDestination(nextPos, 0.25);
}

void MovingButton::eventReachedDestination()
{
    std::pair<float, float> nextPosA = {GET_X(basePosition) + startOffset, GET_Y(basePosition)};
    std::pair<float, float> nextPosB = {GET_X(basePosition) + endOffset, GET_Y(basePosition)};

    if (GET_X(nextPosA) < GET_X(nextPosB)) {
        if (GET_X(movement.getPosition()) < GET_X(basePosition)) {
            movement.setDestination(nextPosB, 0.5);
        } else {
            movement.setDestination(nextPosA, 0.5);
        }

    } else {
        if (GET_X(movement.getPosition()) < GET_X(basePosition)) {
            movement.setDestination(nextPosA, 0.5);
        } else {
            movement.setDestination(nextPosB, 0.5);
        }

    }
}