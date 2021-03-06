/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** TextBox
*/

#include "TextBox.hpp"

static SpriteSheet boxSheet0 {
    {
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
    },
    {
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
    },
};

static SpriteSheet boxSheet1 {
    {
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
    },
    {
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
    },
};

static SpriteSheet boxSheet2 {
    {
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
    },
    {
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,  WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  BLUE,  YELLOW},
        {YELLOW, BLUE,   BLUE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,  BLUE,  YELLOW},
        {YELLOW,YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,  YELLOW,YELLOW},
        {  NONE,YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,  YELLOW,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   BLUE,   BLUE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW, YELLOW, YELLOW, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE, YELLOW,   BLUE, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
        {  NONE,  NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE, YELLOW, YELLOW, YELLOW,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,   NONE,    NONE,  NONE},
    },
};

static Sprite none;

static SpriteSheet boxSheets[4] {boxSheet0, boxSheet1, boxSheet2, boxSheet2};

TextBox::TextBox(std::string &playerName, const std::pair<float, float> &pos)
: Object("textBox", boxSheet0, pos),
playerName(playerName)
{
    actualChar = playerName.size();
    this->sprite.changeSpriteSheet(boxSheets[actualChar]);
    this->text = new Text("text", playerName, 128, RED, none, std::pair<float, float>{39, 10});
    this->sprite.setLoop(true);
    this->sprite.setAnimationSpeed(0.5);
    this->movement.setBlocking(true);
}

TextBox::~TextBox()
{
    delete(this->text);
}

void TextBox::manageEvents(std::map<Input, bool> &inputs)
{
    if (inputs[A_KEY] == true && actualChar != 3) {
        addChar('A');
    } else if (inputs[Z_KEY] == true && actualChar != 3) {
        addChar('Z');
    } else if (inputs[E_KEY] == true && actualChar != 3) {
        addChar('E');
    } else if (inputs[R_KEY] == true && actualChar != 3) {
        addChar('R');
    } else if (inputs[T_KEY] == true && actualChar != 3) {
        addChar('T');
    } else if (inputs[Y_KEY] == true && actualChar != 3) {
        addChar('Y');
    } else if (inputs[U_KEY] == true && actualChar != 3) {
        addChar('U');
    } else if (inputs[I_KEY] == true && actualChar != 3) {
        addChar('I');
    } else if (inputs[O_KEY] == true && actualChar != 3) {
        addChar('O');
    } else if (inputs[P_KEY] == true && actualChar != 3) {
        addChar('P');
    } else if (inputs[Q_KEY] == true && actualChar != 3) {
        addChar('Q');
    } else if (inputs[S_KEY] == true && actualChar != 3) {
        addChar('S');
    } else if (inputs[D_KEY] == true && actualChar != 3) {
        addChar('D');
    } else if (inputs[F_KEY] == true && actualChar != 3) {
        addChar('F');
    } else if (inputs[G_KEY] == true && actualChar != 3) {
        addChar('G');
    } else if (inputs[H_KEY] == true && actualChar != 3) {
        addChar('H');
    } else if (inputs[J_KEY] == true && actualChar != 3) {
        addChar('J');
    } else if (inputs[K_KEY] == true && actualChar != 3) {
        addChar('K');
    } else if (inputs[L_KEY] == true && actualChar != 3) {
        addChar('L');
    } else if (inputs[M_KEY] == true && actualChar != 3) {
        addChar('M');
    } else if (inputs[W_KEY] == true && actualChar != 3) {
        addChar('W');
    } else if (inputs[X_KEY] == true && actualChar != 3) {
        addChar('X');
    } else if (inputs[C_KEY] == true && actualChar != 3) {
        addChar('C');
    } else if (inputs[V_KEY] == true && actualChar != 3) {
        addChar('V');
    } else if (inputs[B_KEY] == true && actualChar != 3) {
        addChar('B');
    } else if (inputs[N_KEY] == true && actualChar != 3) {
        addChar('N');
    } else if (inputs[ERASE_KEY] == true && actualChar != 0) {
        removeChar();
    }
}

void TextBox::display(IDisplayModule *display)
{
    Object::display(display);
    this->text->display(display);
}

void TextBox::addChar(char character)
{
    actualChar++;
    playerName.push_back(character);
    updateText();
}

void TextBox::removeChar()
{
    actualChar--;
    playerName.pop_back();
    updateText();
}

void TextBox::updateText()
{
    text->setText(playerName);
    sprite.changeSpriteSheet(boxSheets[actualChar]);
}

void TextBox::eventHit(Object *other)
{
    (void)other;
    while (actualChar)
        removeChar();
    for (int i = 0; i != 3; i++)
        addChar(rand() % 26 + 65);
}