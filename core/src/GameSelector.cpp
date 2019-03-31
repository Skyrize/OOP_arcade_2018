/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** GameSelector
*/

#include "GameSelector.hpp"

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
    {32, 18},
    {31, 25},
    {31, 28},
    {31, 31},
    {31, 34},
};

static Sprite none;

GameSelector::GameSelector(Arcade &arcade)
: Object("gameSelector", selectorSheet, std::pair<float, float>{27, 15}),
arcade(arcade)
{
    std::vector<std::string> names = arcade.getGameNames();
    this->movement.setBlocking(true);
    for (size_t i = 0; i != names.size(); i++) {
        if (i < 5)
            games.push_back(new Text("text", names[i], 32, BLACK, none, textPositions[i]));
        else
            games.push_back(new Text("text", names[i], 32, BLACK, none));
    }
    while (names[arcade.getActualGame()] != games[0]->getText())
        updatePositions();
}

GameSelector::~GameSelector()
{
    for (size_t i = 0; i != this->games.size(); i++)
        delete(this->games[i]);
    this->games.clear();
}

void GameSelector::eventHit(Object *other)
{
    if (other && other->getName().find("Bullet") == std::string::npos)
        return;
    buttonEvent();
    this->hit = true;
}

void GameSelector::buttonEvent()
{
    arcade.getActualGame()++;
    if (arcade.getGameNames().size() == arcade.getActualGame())
        arcade.getActualGame() = 0;
    updatePositions();
}

void GameSelector::display(IDisplayModule *display)
{
    Object::display(display);

    for (size_t i = 0; i != games.size() && i != 5; i++) {
        games[i]->display(display);
    }
}

void GameSelector::updatePositions()
{
    std::string tmp = games[0]->getText();

    for (size_t i = 0; i != games.size() - 1; i++)
        games[i]->setText(games[i + 1]->getText());
    games[games.size() - 1]->setText(tmp);
}