/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** GameSelector
*/

#include "GameSelector.hpp"

static Sprite selectorSprite {
    {}
};

GameSelector::GameSelector(Arcade &arcade)
: Object("gameSelector", selectorSprite, std::pair<float, float>{5, 5}),
arcade(arcade)
{
}

GameSelector::~GameSelector()
{
}
