/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakeScene
*/

#include "SnakeScene.hpp"
#include "Snake.hpp"

static Sprite none {{}};

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
},
};
static SpriteSheet horizontalBorderSprite{
{
    { RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED},
},
{
    { YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW},
},
{
    { WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE},
}
};

static Sprite slabSprite {
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
    {BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE, BLUE, BLUE, BLUE, NONE, NONE, NONE},
};

/*

écran = 100 / 57



96 / 3 = 32
54 / 3 = 18

100 -> - 15 - 1 = 84 -> /3 = 28
57 -> - 11 - 1 = 47 -> / 3 = 15
*/

SnakeScene::SnakeScene()
: Scene("SnakeScene", none)
{
    this->addObject(new Snake);
    addObject(new Object("BorderLeft", verticalBorderSprite, std::pair<float, float>{7, 9}))->getMovement().setBlocking(true);
    addObject(new Object("BorderRight", verticalBorderSprite, std::pair<float, float>{92, 9}))->getMovement().setBlocking(true);
    addObject(new Object("BorderTop", horizontalBorderSprite, std::pair<float, float>{7, 9}))->getMovement().setBlocking(true);
    addObject(new Object("BorderBot", horizontalBorderSprite, std::pair<float, float>{7, 55}))->getMovement().setBlocking(true);
    addObject(new Object("Slabs", slabSprite, std::pair<float, float>{8, 10}));
}

SnakeScene::~SnakeScene()
{
}

void SnakeScene::manageEvents(std::map<Input, bool> &inputs)
{
    objects["Snake"]->manageEvents(inputs);
}
