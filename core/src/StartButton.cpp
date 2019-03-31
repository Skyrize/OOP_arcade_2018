/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** StartButton
*/

#include "StartButton.hpp"

static SpriteSheet startButtonSheet {
    {
        {  NONE,  NONE,  NONE,  NONE,  NONE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  NONE,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,YELLOW,YELLOW,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,YELLOW,YELLOW,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,YELLOW,YELLOW,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,YELLOW,YELLOW,  NONE,  NONE,  NONE},
        {YELLOW,YELLOW,YELLOW,YELLOW,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,YELLOW,YELLOW,YELLOW,YELLOW},
        {  NONE,  NONE,  NONE,YELLOW,YELLOW,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,YELLOW,YELLOW,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,YELLOW,YELLOW,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,YELLOW,YELLOW,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,  NONE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  NONE,  NONE,  NONE,  NONE,  NONE},
    },
    {
        {  NONE,  NONE,  NONE,  NONE,  NONE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  NONE,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,  BLUE,  BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE,  BLUE,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  BLUE,  BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE,  BLUE,  NONE,  NONE,  NONE},
        {  BLUE,  BLUE,  BLUE,  BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE,  BLUE,  BLUE,  BLUE},
        {  NONE,  NONE,  NONE,  BLUE,  BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE,  BLUE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,  BLUE,  BLUE,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,YELLOW,  BLUE,  BLUE,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,  NONE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  NONE,  NONE,  NONE,  NONE,  NONE},
    },
    {
        {  NONE,  NONE,  NONE,  NONE,  NONE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,  NONE,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,   RED,   RED,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,   RED,   RED,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,   RED,   RED,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,   RED,   RED,  NONE,  NONE,  NONE},
        {   RED,   RED,   RED,   RED,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,   RED,   RED,   RED,   RED},
        {  NONE,  NONE,  NONE,   RED,   RED,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,   RED,   RED,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,   RED,   RED,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,   RED,   RED,  NONE,  NONE,  NONE,  NONE},
        {  NONE,  NONE,  NONE,  NONE,  NONE,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,   RED,  NONE,  NONE,  NONE,  NONE,  NONE},
    },
};

StartButton::StartButton(MenuModule &parent, Arcade &arcade)
: Text("osef", "START", 32, BLACK, startButtonSheet, std::pair<float, float>{38, 7}),
parent(parent),
arcade(arcade)
{
    this->movement.setBlocking(true);
    this->textPos = {45, 9};
}

void StartButton::eventHit(Object *other)
{
    if (other && other->getName().find("Bullet") == std::string::npos)
        return;
    parent.eventButtonTriggered();
    this->hit = true;
}

void StartButton::buttonEvent()
{
    parent.exitModule();
}

float StartButton::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    float delta = Object::update(display, objects);
    
    if (sprite.isAnimated() == false && hit == true) {
        hit = false;
		buttonEvent();
    }
    return delta;
}