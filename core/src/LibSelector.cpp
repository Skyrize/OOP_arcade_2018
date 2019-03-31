/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** LibSelector
*/

#include "LibSelector.hpp"

static SpriteSheet selectorSheet {
    {
        {  NONE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,    BLUE,    BLUE,   BLUE,   BLUE,   BLUE,   BLUE,    BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   NONE},
        {  BLUE,   BLUE,    RED,    RED,    RED,   RED,   RED,     RED,     RED,    RED,    RED,    RED,    RED,     RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE},
        {  BLUE,    RED,    RED,    RED,    RED,   RED,   RED,     RED,     RED,    RED,    RED,    RED,    RED,     RED,    RED,    RED,    RED,    RED,    RED,   BLUE},
        {  BLUE,    RED,    RED,    RED,    RED,   RED,   RED,     RED,     RED,    RED,    RED,    RED,    RED,     RED,    RED,    RED,    RED,    RED,    RED,   BLUE},
        {  BLUE,    RED,    RED,    RED,    RED,   RED,   RED,     RED,     RED,    RED,    RED,    RED,    RED,     RED,    RED,    RED,    RED,    RED,    RED,   BLUE},
        {  BLUE,    RED,    RED,    RED,    RED,   RED,   RED,     RED,     RED,    RED,    RED,    RED,    RED,     RED,    RED,    RED,    RED,    RED,    RED,   BLUE},
        {  BLUE,    RED,    RED,    RED,    RED,   RED,   RED,     RED,     RED,    RED,    RED,    RED,    RED,     RED,    RED,    RED,    RED,    RED,    RED,   BLUE},
        {  BLUE,   BLUE,    RED,    RED,    RED,   RED,   RED,     RED,     RED,    RED,    RED,    RED,    RED,     RED,    RED,    RED,    RED,    RED,   BLUE,   BLUE},
        {  NONE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,    BLUE,    BLUE,   BLUE,   BLUE,   BLUE,   BLUE,    BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,  WHITE,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   BLUE,   NONE},
        {  NONE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,    BLUE,     BLUE,   BLUE,   BLUE,   BLUE,   BLUE,    BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   NONE},
    },
    {
        {  NONE,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,   YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,   NONE},
        {YELLOW,  YELLOW,    BLUE,    BLUE,  BLUE,   BLUE,   BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,  YELLOW,  YELLOW},
        {YELLOW,    BLUE,    BLUE,    BLUE,   BLUE,  BLUE,  BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,  YELLOW},
        {YELLOW,    BLUE,    BLUE,    BLUE,   BLUE,  BLUE,  BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,  YELLOW},
        {YELLOW,    BLUE,    BLUE,    BLUE,   BLUE,  BLUE,  BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,  YELLOW},
        {YELLOW,    BLUE,    BLUE,    BLUE,   BLUE,  BLUE,  BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,  YELLOW},
        {YELLOW,    BLUE,    BLUE,    BLUE,   BLUE,  BLUE,  BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,  YELLOW},
        {YELLOW,  YELLOW,    BLUE,    BLUE,  BLUE,   BLUE,   BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,  YELLOW,  YELLOW},
        {  NONE,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,   YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  WHITE,  WHITE,   WHITE,   WHITE,   WHITE,    WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  YELLOW,   NONE},
        {  NONE,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,   YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,   NONE},
    },
    {
        {  NONE,   RED,   RED,   RED,   RED,       RED,       RED,        RED,   RED,   RED,   RED,   RED,   RED,    RED,   RED,   RED,   RED,   RED,   RED,   NONE},
        {RED,   RED,   YELLOW,   YELLOW,           YELLOW,           YELLOW,            YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,    YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   RED,   RED},
        {RED,   YELLOW,   YELLOW,   YELLOW,        YELLOW,        YELLOW,        YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,    YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   RED},
        {RED,   YELLOW,   YELLOW,   YELLOW,        YELLOW,        YELLOW,        YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,    YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   RED},
        {RED,   YELLOW,   YELLOW,   YELLOW,        YELLOW,        YELLOW,        YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,    YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   RED},
        {RED,   YELLOW,   YELLOW,   YELLOW,        YELLOW,        YELLOW,        YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,    YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   RED},
        {RED,   YELLOW,   YELLOW,   YELLOW,        YELLOW,        YELLOW,        YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,    YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   RED},
        {RED,   RED,   YELLOW,   YELLOW,           YELLOW,           YELLOW,            YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,    YELLOW,   YELLOW,   YELLOW,   YELLOW,   YELLOW,   RED,   RED},
        {  NONE,   RED,   RED,   RED,   RED,       RED,       RED,        RED,   RED,   RED,   RED,   RED,   RED,    RED,   RED,   RED,   RED,   RED,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,  WHITE,  WHITE,  WHITE,    WHITE,    WHITE,     WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,   RED,   NONE},
        {  NONE,   RED,   RED,   RED,   RED,   RED,RED,RED,   RED,   RED,   RED,   RED,   RED,    RED,   RED,   RED,   RED,   RED,   RED,   NONE},
    },
};

const static std::pair<float, float> textPositions[5] = {
    {57, 18},
    {56, 25},
    {56, 28},
    {56, 31},
    {56, 34},
};

static Sprite none;

LibSelector::LibSelector(MenuModule &parent, Arcade &arcade)
: Object("alibSelector", selectorSheet, std::pair<float, float>{52, 15}),
parent(parent),
arcade(arcade)
{
    std::vector<std::string> names = arcade.getLibNames();

    this->movement.setBlocking(true);
    for (size_t i = 0; i != names.size(); i++) {
        if (i < 5)
            libs.push_back(new Text("text", names[i], 32, BLACK, none, textPositions[i]));
        else
            libs.push_back(new Text("text", names[i], 32, BLACK, none));
    }
    while (names[arcade.getActualLib()] != libs[0]->getText())
        updatePositions();
}

LibSelector::~LibSelector()
{
}

void LibSelector::eventHit(Object *other)
{
    if (other && other->getName().find("Bullet") == std::string::npos)
        return;
    buttonEvent();
    this->hit = true;
}

void LibSelector::buttonEvent()
{
    arcade.getActualLib()++;
    if (arcade.getLibNames().size() == arcade.getActualLib())
        arcade.getActualLib() = 0;
    updatePositions();
    parent.changeLib();
}

void LibSelector::display(IDisplayModule *display)
{
    Object::display(display);

    for (size_t i = 0; i != libs.size() && i != 5; i++) {
        libs[i]->display(display);
    }
}

void LibSelector::updatePositions()
{
    std::string tmp = libs[0]->getText();

    for (size_t i = 0; i != libs.size() - 1; i++)
        libs[i]->setText(libs[i + 1]->getText());
    libs[libs.size() - 1]->setText(tmp);
}