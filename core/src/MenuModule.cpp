/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** MenuModule.cpp
*/

#include "MenuModule.hpp"
#include "Sprites.hpp"
#include "Invader.hpp"
#include "MovingButton.hpp"
#include "Button.hpp"
#include "Star.hpp"
#include "Text.hpp"
#include "TextBox.hpp"
#include "ScoreBoard.hpp"
#include "StartButton.hpp"
#include "GameSelector.hpp"
#include "LibSelector.hpp"
#include <iostream>

#define NB_STARS 10
#define SPAWN_STAR_TIMER 0.2

static Sprite none{{}};
static SpriteSheet verticalBorderSprite{
{
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
    {RED},
},
{
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
    {YELLOW},
},
{
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
    {WHITE},
},
};
static SpriteSheet horizontalBorderSprite{
{
    { RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED},
},
{
    { YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW},
},
{
    { WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE},
}
};

static SpriteSheet nextButtonSheet {
    {
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, RED, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},

        {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,                                             WHITE, RED, RED, RED, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE, NONE, NONE},
        {RED, RED, RED, RED, RED, RED, RED, RED, RED,                                             RED, RED, RED, RED, RED, RED, WHITE, WHITE, WHITE,  NONE, NONE, NONE},
        {RED, RED, RED, RED, RED, RED, RED, RED, RED,                                             RED, RED, RED, RED, RED, RED, RED, RED, WHITE, WHITE,WHITE, NONE},
        {RED, RED, RED, RED, RED, RED, RED, RED, RED,                                             RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,WHITE,WHITE},
        {RED, RED, RED, RED, RED, RED, RED, RED, RED,                                             RED, RED, RED, RED, RED, RED, RED, RED, WHITE, WHITE,WHITE, NONE},
        {RED, RED, RED, RED, RED, RED, RED, RED, RED,                                             RED, RED, RED, RED, RED, RED, WHITE, WHITE, WHITE,  NONE, NONE, NONE},
        {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,                                             WHITE, RED, RED, RED, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE, NONE, NONE},

        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, RED, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
    },
    {
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, YELLOW, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},

        {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,                                             WHITE, YELLOW, YELLOW, YELLOW, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE, NONE, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,                                             YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, WHITE, WHITE, WHITE,  NONE, NONE, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,                                             YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, WHITE, WHITE,WHITE, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,                                             YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,WHITE,WHITE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,                                             YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, WHITE, WHITE,WHITE, NONE},
        {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,                                             YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, WHITE, WHITE, WHITE,  NONE, NONE, NONE},
        {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,                                             WHITE, YELLOW, YELLOW, YELLOW, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE, NONE, NONE},

        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, YELLOW, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
    },
    {
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, BLUE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},

        {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,                                             WHITE, BLUE, BLUE, BLUE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE, NONE, NONE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,                                             BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, WHITE,  NONE, NONE, NONE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,                                             BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE,WHITE, NONE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,                                             BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,WHITE,WHITE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,                                             BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE,WHITE, NONE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,                                             BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, WHITE, WHITE, WHITE,  NONE, NONE, NONE},
        {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,                                             WHITE, BLUE, BLUE, BLUE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE, NONE, NONE},

        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, BLUE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,                                             WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, NONE, NONE},
    },
};

static SpriteSheet backButtonSheet {
    {
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   RED, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   RED,   RED,   RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
        { NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED},
        { NONE, WHITE, WHITE, WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED},
        {WHITE, WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED},
        { NONE, WHITE, WHITE, WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED},
        { NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED},
        { NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   RED,   RED,   RED, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   RED, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
    },
    {
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   YELLOW, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   YELLOW,   YELLOW,   YELLOW, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
        { NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW},
        { NONE, WHITE, WHITE, WHITE,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW},
        {WHITE, WHITE,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW},
        { NONE, WHITE, WHITE, WHITE,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW},
        { NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW},
        { NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   YELLOW,   YELLOW,   YELLOW, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   YELLOW, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
    },
    {
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   BLUE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   BLUE,   BLUE,   BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
        { NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE},
        { NONE, WHITE, WHITE, WHITE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE},
        {WHITE, WHITE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE},
        { NONE, WHITE, WHITE, WHITE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE},
        { NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE},
        { NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   BLUE,   BLUE,   BLUE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,   BLUE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
        { NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE, WHITE, WHITE, WHITE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE,  NONE},
    },
};

static SpriteSheet mainButtonSheet {
    {
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED, YELLOW,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE},
        {NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE},
        {BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED, YELLOW, YELLOW, YELLOW,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE},
        {NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE},
        {NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,    RED,    RED,    RED,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW, YELLOW, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED, YELLOW,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,    RED,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,    RED,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   BLUE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   BLUE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
    },
    {
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE},
        {NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   BLUE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE},
        {NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   BLUE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE},
        {RED,     RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   BLUE,   BLUE,   BLUE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED},
        {NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE},
        {NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE},
        {NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW,   BLUE, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW, YELLOW, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED, YELLOW,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,    RED,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    RED,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
    },
    {
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE},
        {NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,    RED,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE},
        {NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,    RED,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE},
        {YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,    RED,    RED,    RED,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW},
        {NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,    RED,    RED,    RED,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE},
        {NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE},
        {NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,    RED,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,    RED,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE,   BLUE,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW,   BLUE, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
        {NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE},
    },
};

MenuModule::MenuModule(Arcade &arcade)
: Scene("MenuModule", none),
arcade(arcade),
playerName(arcade.getPlayerName())
{
    //addObject(new Object("BorderLeft", verticalBorderSprite))->getMovement().setBlocking(true);
    //addObject(new Object("BorderRight", verticalBorderSprite, std::pair<float, float>{99, 0}))->getMovement().setBlocking(true);
    //addObject(new Object("BorderTop", horizontalBorderSprite))->getMovement().setBlocking(true);
    //addObject(new Object("BorderBot", horizontalBorderSprite, std::pair<float, float>{0, 56}))->getMovement().setBlocking(true);
    addObject(new Invader(*this, std::pair<float, float>{46, 40}));

	this->pannels.push_back(new Scene("mainPannel", none));
    pannels[0]->addObject(new Button(*this, 1, "mainPannel-MainButton", mainButtonSheet, std::pair<float, float>{34, 6}));
    pannels[0]->addObject(new MovingButton(*this, 3, -3, 3, "mainPannel-ScoreButton", backButtonSheet, std::pair<float, float>{3, 10}));
    pannels[0]->addObject(new Text("ButtonText1", "HIGHSCORES", 32, WHITE, none, std::pair<float, float>{5, 6}));
    pannels[0]->addObject(new MovingButton(*this, 1, 3, -3, "mainPannel-NextButton", nextButtonSheet, std::pair<float, float>{76, 10}));
    pannels[0]->addObject(new Text("ButtonText2", "PLAYER NAME", 32, WHITE, none, std::pair<float, float>{78, 6}));
    pannels[0]->addObject(new Text("Tips0", "Use SpaceBar to shoot buttons", 16, WHITE, none, std::pair<float, float>{75, 53}));
    pannels[0]->addObject(new Text("Tips1", "Use '1' and '2' to switch display", 16, WHITE, none, std::pair<float, float>{37, 53}));
    pannels[0]->addObject(new Text("Tips2", "Use '3' and '4 to switch game", 16, WHITE, none, std::pair<float, float>{3, 53}));
	this->pannels.push_back(new Scene("namePannel", none));
    pannels[1]->addObject(new MovingButton(*this, 0, -3, 3, "namePannel-BackButton", backButtonSheet, std::pair<float, float>{3, 10}));
    pannels[1]->addObject(new Text("ButtonText1", "BACK", 32, WHITE, none, std::pair<float, float>{5, 6}));
    pannels[1]->addObject(new MovingButton(*this, 2, 3, -3, "namePannel-NextButton", nextButtonSheet, std::pair<float, float>{76, 10}));
    pannels[1]->addObject(new Text("ButtonText2", "GAME SELECTION", 32, WHITE, none, std::pair<float, float>{75, 6}));
    pannels[1]->addObject(new Text("ButtonText3", "ENTER YOUR NAME", 32, WHITE, none, std::pair<float, float>{37, 3}));
    pannels[1]->addObject(new Text("Tips0", "A-Z letters only", 16, WHITE, none, std::pair<float, float>{75, 53}));
    pannels[1]->addObject(new Text("Tips1", "Shoot for a random name", 16, WHITE, none, std::pair<float, float>{37, 53}));
    pannels[1]->addObject(new TextBox(playerName, std::pair<float, float>{35, 7}));
	this->pannels.push_back(new Scene("menuPannel", none));
    pannels[2]->addObject(new MovingButton(*this, 1, -3, 3, "menuPannel-BackButton", backButtonSheet, std::pair<float, float>{3, 10}));
    pannels[2]->addObject(new Text("ButtonText1", "BACK", 32, WHITE, none, std::pair<float, float>{5, 6}));
    pannels[2]->addObject(new MovingButton(*this, 3, 3, -3, "menuPannel-NextButton", nextButtonSheet, std::pair<float, float>{76, 10}));
    pannels[2]->addObject(new StartButton(*this, arcade));
    pannels[2]->addObject(new GameSelector(arcade));
    pannels[2]->addObject(new LibSelector(*this, arcade));
    pannels[2]->addObject(new Text("ButtonText3", "SELECT GAME / SELECT DISPLAY", 32, WHITE, none, std::pair<float, float>{28, 3}));
    pannels[2]->addObject(new Text("ButtonText2", "SCORES", 32, WHITE, none, std::pair<float, float>{81, 6}));
	this->pannels.push_back(new Scene("scorePannel", none));
    pannels[3]->addObject(new MovingButton(*this, 0, 3, -3, "scorePannel-ScoreButton", nextButtonSheet, std::pair<float, float>{76, 10}));
    pannels[3]->addObject(new Text("ButtonText1", "BACK", 32, WHITE, none, std::pair<float, float>{81, 6}));
    pannels[3]->addObject(new Text("buttonText2", "Score", 16, BLACK, none, std::pair<float, float>{47, 19}));
    pannels[3]->addObject(new Text("buttonText3", "Down", 16, BLACK, none, std::pair<float, float>{47, 21}));
    pannels[3]->addObject(new Text("buttonText4", "Change", 16, BLACK, none, std::pair<float, float>{64, 19}));
    pannels[3]->addObject(new Text("buttonText5", "Game", 16, BLACK, none, std::pair<float, float>{64, 21}));
    pannels[3]->addObject(new ScoreBoard(*pannels[3], arcade.getHighScores(), std::pair<float, float>{2, 2}));
}

MenuModule::~MenuModule()
{

}

void MenuModule::init(const std::string &playerName, const int &highScore)
{
    (void)playerName;
    (void)highScore;
}

void MenuModule::stop()
{
}

const std::string &MenuModule::getName() const
{
    return _name;
}

int MenuModule::getHighScore() const
{
    return 0;
}

void MenuModule::run(IDisplayModule *library, std::map<Input, bool> &inputs)
{
    manageEvents(inputs);
    update(library);
    display(library);
    if (changer == true) {
        arcade.changeDisplay(arcade.getActualLib());
        changer = false;
    }
    if (exiting == true)
        arcade.changeGame(arcade.getActualGame());
}

void MenuModule::restart() const
{
}

void MenuModule::display(IDisplayModule *display)
{
    Scene::display(display);
    pannels[actualPannel]->display(display);
}

float MenuModule::update(IDisplayModule *display)
{
	std::map<std::string, Object *> merge = this->objects;
    std::map<std::string, Object *> objects = pannels[actualPannel]->getObjects();    

	merge.insert(objects.begin(), objects.end());
    float delta = Object::update(display, merge);

	for (auto &e : merge)
		if (e.second)
			e.second->update(display, merge);
    if (nbStars != NB_STARS && (this->starSpawnTimer -= delta) <= 0) {
        starSpawnTimer = SPAWN_STAR_TIMER;
        addObject(new Star("AStar-" + std::to_string(nbStars)));
        nbStars++;
    }
    for (size_t i = 0; i != 4; i++) {
        if (i != actualPannel)
            pannels[actualPannel]->update(display);
    }
	return delta;
}

void MenuModule::manageEvents(std::map<Input, bool> &inputs)
{
    this->objects["SpaceInvader"]->manageEvents(inputs);
    this->pannels[actualPannel]->manageEvents(inputs);
}

Scene *MenuModule::getActualPannel()
{
    return pannels[actualPannel];
}

void MenuModule::goToPannel(const int &index)
{
    this->actualPannel = index;
    if (actualPannel != 1 && playerName.empty() == true) {
        for (int i = 0; i != 3; i++)
            ((TextBox *)this->pannels[1]->getObjects()["textBox"])->addChar('A');
    }
    static_cast<Invader *>(objects["SpaceInvader"])->replaceCenter();
}

void MenuModule::eventButtonTriggered()
{
    std::map<std::string, Object *> &pannelObjects = pannels[actualPannel]->getObjects();    

    for (auto &e : pannelObjects) {
        if (e.second) {
            e.second->getAnimation().setAnimationSpeed(0.1);
            e.second->getAnimation().setNbLoop(2);
        }
    }
}

void MenuModule::exitModule()
{
    this->exiting = true;
}

void MenuModule::changeLib()
{
    this->changer = true;
}