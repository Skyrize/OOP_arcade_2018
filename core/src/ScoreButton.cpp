/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreButton
*/

#include "ScoreButton.hpp"

ScoreButton::ScoreButton(ScoreBoard &parent, void (ScoreBoard::*fptr)(), SpriteSheet &spriteSheet, const std::pair<float, float> &position)
: Object("ScoreButton" + std::to_string(position.first), spriteSheet, position),
parent(parent),
fptr(fptr)
{
    movement.setBlocking(true);
}

ScoreButton::ScoreButton(ScoreBoard &parent, void (ScoreBoard::*fptr)(), Sprite &sprite, const std::pair<float, float> &position)
: Object("ScoreButton" + std::to_string(position.first), sprite, position),
parent(parent),
fptr(fptr)
{
    movement.setBlocking(true);
}


ScoreButton::~ScoreButton()
{
}

void ScoreButton::eventHit(Object *other)
{
    (void)other;
    (parent.*fptr)();
}