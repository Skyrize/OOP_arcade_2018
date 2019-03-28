/*
** EPITECH PROJECT, 2040
** OOP_arcade_2040
** File description:
** MainMenuScene.cpp
*/

#include "MainMenuScene.hpp"
#include "Sprites.hpp"
#include "Invader.hpp"
#include "MovingButton.hpp"
#include "Button.hpp"
#include "Star.hpp"
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

MainMenuScene::MainMenuScene()
: Scene("MainMenuScene", none)
{
    //addObject(new Object("BorderLeft", verticalBorderSprite))->getMovement().setBlocking(true);
    //addObject(new Object("BorderRight", verticalBorderSprite, std::pair<float, float>{99, 0}))->getMovement().setBlocking(true);
    //addObject(new Object("BorderTop", horizontalBorderSprite))->getMovement().setBlocking(true);
    //addObject(new Object("BorderBot", horizontalBorderSprite, std::pair<float, float>{0, 56}))->getMovement().setBlocking(true);
    addObject(new Invader(*this, std::pair<float, float>{46, 50}));


	this->pannels.push_back(new Scene("mainPannel", none));
    pannels[0]->addObject(new Button(*this, 1, "mainPannel-MainButton", mainButtonSheet, std::pair<float, float>{34, 6}));
    pannels[0]->addObject(new MovingButton(*this, 3, -3, 3, "mainPannel-ScoreButton", backButtonSheet, std::pair<float, float>{10, 10}));
	this->pannels.push_back(new Scene("namePannel", none));
    pannels[1]->addObject(new MovingButton(*this, 0, -3, 3, "namePannel-BackButton", backButtonSheet, std::pair<float, float>{10, 10}));
    pannels[1]->addObject(new MovingButton(*this, 2, 3, -3, "namePannel-NextButton", nextButtonSheet, std::pair<float, float>{70, 10}));
	this->pannels.push_back(new Scene("menuPannel", none));
    pannels[2]->addObject(new MovingButton(*this, 1, -3, 3, "menuPannel-BackButton", backButtonSheet, std::pair<float, float>{10, 10}));
    pannels[2]->addObject(new MovingButton(*this, 3, 3, -3, "menuPannel-NextButton", nextButtonSheet, std::pair<float, float>{70, 10}));
	this->pannels.push_back(new Scene("scorePannel", none));
    pannels[3]->addObject(new MovingButton(*this, 0, 3, -3, "scorePannel-ScoreButton", nextButtonSheet, std::pair<float, float>{10, 10}));
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::display(IDisplayModule *display)
{
    Scene::display(display);
    pannels[actualPannel]->display(display);
}

float MainMenuScene::update(IDisplayModule *display)
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
	return delta;
}

void MainMenuScene::manageEvents(std::map<Input, bool> &inputs)
{
    this->objects["SpaceInvader"]->manageEvents(inputs);
}

Scene *MainMenuScene::getActualPannel()
{
    return pannels[actualPannel];
}

void MainMenuScene::goToPannel(const int &index)
{
    this->actualPannel = index;
}

void MainMenuScene::eventButtonTriggered()
{
    std::map<std::string, Object *> &pannelObjects = pannels[actualPannel]->getObjects();    

    for (auto &e : objects) {
        if (e.second) {
            e.second->getAnimation().setAnimationSpeed(0.1);
            e.second->getAnimation().setNbLoop(4);
        }
    }
    for (auto &e : pannelObjects) {
        if (e.second) {
            e.second->getAnimation().setAnimationSpeed(0.1);
            e.second->getAnimation().setNbLoop(4);
        }
    }
}