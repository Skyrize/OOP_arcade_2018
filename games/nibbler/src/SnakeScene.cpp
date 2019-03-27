/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakeScene
*/

#include <cstdlib>
#include "SnakeScene.hpp"
#include "Snake.hpp"
#include "StartPannel.hpp"
#include "EndPannel.hpp"

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
    { RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, RED,  RED,  RED,  RED,  RED,  RED},
},
{
    { YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW},
},
{
    { WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE, WHITE,  WHITE,  WHITE,  WHITE,  WHITE,  WHITE},
}
};

static SpriteSheet pannelSpriteSheet {
    {
        {NONE,  NONE,  NONE,  NONE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE, NONE, NONE, NONE, NONE},
        {NONE,  NONE,   BLUE,   BLUE,  BLUE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  BLUE,  BLUE,  BLUE, NONE, NONE},
        { BLUE,   BLUE,   BLUE, WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  BLUE,  BLUE,  BLUE},
        {NONE,  NONE,   BLUE,   BLUE,  BLUE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  BLUE,  BLUE,  BLUE, NONE, NONE},
        {NONE,  NONE,  NONE,  NONE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE,  BLUE, NONE, NONE, NONE, NONE},
    },
    {
        {NONE,  NONE,  NONE,  NONE,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, NONE, NONE, NONE, NONE},
        {NONE,  NONE,   RED,   RED,  RED,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  RED,  RED,  RED, NONE, NONE},
        { RED,   RED,   RED, WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  RED,  RED,  RED},
        {NONE,  NONE,   RED,   RED,  RED,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  RED,  RED,  RED, NONE, NONE},
        {NONE,  NONE,  NONE,  NONE,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED,  RED, NONE, NONE, NONE, NONE},
    },
    {
        {NONE,  NONE,  NONE,  NONE,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, NONE, NONE, NONE, NONE},
        {NONE,  NONE,   YELLOW,   YELLOW,  YELLOW,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  YELLOW,  YELLOW,  YELLOW, NONE, NONE},
        { YELLOW,   YELLOW,   YELLOW, WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  YELLOW,  YELLOW,  YELLOW},
        {NONE,  NONE,   YELLOW,   YELLOW,  YELLOW,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,  YELLOW,  YELLOW,  YELLOW, NONE, NONE},
        {NONE,  NONE,  NONE,  NONE,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW, NONE, NONE, NONE, NONE},
    }
};

static SpriteSheet fruitSpriteSheet {
    {
        {RED}
    },
    {
        {YELLOW}
    },
};

/*

écran = 100 / 57



96 / 3 = 32
54 / 3 = 18

100 -> - 15 - 1 = 84 -> /3 = 28
57 -> - 11 - 1 = 47 -> / 3 = 15
*/

static Sprite block {
    {
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
        {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
    },
};

static Sprite barH {
    {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE}
};

static Sprite barV {
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
    {BLUE},
};

SnakeScene::SnakeScene()
: Scene("SnakeScene", none)
{
    score = new Text("Score", "Score = 0", 16, BLACK, none, std::pair<float, float>{15, 2});
    speedMode = new Text("Mode", "Speed mode : OFF", 16, BLACK, none, std::pair<float, float>{75, 2});
    displayedMap = new Text("DisplayedMap", "Map : ", 16, BLACK, none, std::pair<float, float>{40, 2});
    endMenu = new EndPannel(this->scoreValue);
    startMenu = new StartPannel();
    fruit = new Object("SnakeFruit", fruitSpriteSheet);

    fruit->getAnimation().setAnimationSpeed(0.4);
    addObject(new Object("APannel", pannelSpriteSheet, std::pair<float, float>{5, 0}));
    addObject(new Object("BorderLeft-1", verticalBorderSprite, std::pair<float, float>{5, 7}));
    addObject(new Object("BorderLeft-2", verticalBorderSprite, std::pair<float, float>{5, 10}));
    addObject(new Object("BorderRight-1", verticalBorderSprite, std::pair<float, float>{94, 7}));
    addObject(new Object("BorderRight-2", verticalBorderSprite, std::pair<float, float>{94, 10}));
    addObject(new Object("BorderTop-1", horizontalBorderSprite, std::pair<float, float>{5, 6}));
    addObject(new Object("BorderTop-2", horizontalBorderSprite, std::pair<float, float>{9, 6}));
    addObject(new Object("BorderBot-1", horizontalBorderSprite, std::pair<float, float>{5, 56}));
    addObject(new Object("BorderBot-2", horizontalBorderSprite, std::pair<float, float>{9, 56}));
    addObject(new Object("BorderLeft", verticalBorderSprite, std::pair<float, float>{7, 9}))->getMovement().setBlocking(true);
    addObject(new Object("BorderRight", verticalBorderSprite, std::pair<float, float>{92, 9}))->getMovement().setBlocking(true);
    addObject(new Object("BorderTop", horizontalBorderSprite, std::pair<float, float>{7, 8}))->getMovement().setBlocking(true);
    addObject(new Object("BorderBot", horizontalBorderSprite, std::pair<float, float>{7, 54}))->getMovement().setBlocking(true);
    addObject(score);
    addObject(startMenu);
    addObject(speedMode);
    addObject(displayedMap);
    this->maps.resize(3);
    maps[1].push_back(new Object("Block1", block, std::pair<float, float>{12, 12}));
    maps[1].push_back(new Object("Block2", block, std::pair<float, float>{12, 42}));
    maps[1].push_back(new Object("Block3", block, std::pair<float, float>{30, 27}));
    maps[1].push_back(new Object("Block32", block, std::pair<float, float>{62, 27}));
    maps[1].push_back(new Object("Block4", block, std::pair<float, float>{80, 12}));
    maps[1].push_back(new Object("Block5", block, std::pair<float, float>{80, 42}));
    maps[2].push_back(new Object("BarH1", barH, std::pair<float, float>{10, 12}));
    maps[2].push_back(new Object("BarH2", barH, std::pair<float, float>{40, 20}));
    maps[2].push_back(new Object("BarH3", barH, std::pair<float, float>{60, 12}));
    maps[2].push_back(new Object("BarH4", barH, std::pair<float, float>{40, 30}));
    maps[2].push_back(new Object("BarH5", barH, std::pair<float, float>{10, 42}));
    maps[2].push_back(new Object("BarH6", barH, std::pair<float, float>{60, 42}));
    maps[2].push_back(new Object("BarV1", barV, std::pair<float, float>{20, 11}));
    maps[2].push_back(new Object("BarV2", barV, std::pair<float, float>{40, 20}));
    maps[2].push_back(new Object("BarV3", barV, std::pair<float, float>{80, 11}));
    maps[2].push_back(new Object("BarV4", barV, std::pair<float, float>{40, 21}));
    maps[2].push_back(new Object("BarV5", barV, std::pair<float, float>{10, 30}));
    maps[2].push_back(new Object("BarV6", barV, std::pair<float, float>{60, 30}));
    loadMap();
}

SnakeScene::~SnakeScene()
{
}

void SnakeScene::manageEvents(std::map<Input, bool> &inputs)
{
    if (objects["Snake"])
        objects["Snake"]->manageEvents(inputs);
    if (inputs[SPACE_KEY] == true) {
        if (objects["StartMenu"]) {
            removeObject("StartMenu");
            launchSnake();
        } else if (objects["EndMenu"]) {
            removeObject("EndMenu");
            addObject(this->startMenu);
        }
    }
    if (objects["StartMenu"] || (objects["Snake"] && objects["Snake"]->getMovement().isMoving() == false)) {
        if (inputs[A_KEY] == true) {
            previousMap();
        } else if (inputs[E_KEY] == true) {
            nextMap();
        }
        if (inputs[S_KEY] == true)
            changeMode();
    }
}

void SnakeScene::unloadMap()
{
    for (auto &e : maps[actualMap])
            if (objects[e->getName()])
                removeObject(e->getName());
}

void SnakeScene::loadMap()
{
    for (auto &e : maps[actualMap])
        addObject(e);
    this->displayedMap->setText("Map : n-" + std::to_string(actualMap + 1));
    replaceFruit();
}

void SnakeScene::previousMap()
{
    if (actualMap == 0) {
        unloadMap();
        actualMap = maps.size() - 1;
        loadMap();
    } else {
        unloadMap();
        actualMap--;
        loadMap();
    }
}

void SnakeScene::nextMap()
{
    if (actualMap == maps.size() - 1) {
        unloadMap();
        actualMap = 0;
        loadMap();
    } else {
        unloadMap();
        actualMap++;
        loadMap();
    }
}

void SnakeScene::changeMode()
{
    if (this->speedModeValue == true) {
        this->speedModeValue = false;
        speedMode->setText("Speed mode : OFF");
    } else {
        this->speedModeValue = true;
        speedMode->setText("Speed mode : ON");
    }
}

void SnakeScene::eventFruitEaten()
{
    for (auto &e : objects) {
        if (e.second && e.second->getName().find("Snake") == std::string::npos) {
            e.second->getAnimation().setAnimationSpeed(0.2);
            e.second->getAnimation().setNbLoop(2);
        }
    }
    addPoints();
    replaceFruit();
}

void SnakeScene::addPoints()
{
    if (fruit->getAnimation().isAnimated()) {
        scoreValue += 50;
        fruit->getAnimation().goToSprite(0);
    } else {
        scoreValue += 10;
    }
    if (scoreValue > highScore)
        highScore = scoreValue;
    score->setText("Score = " + std::to_string(scoreValue));
}

void SnakeScene::replaceFruit()
{
    fruit->getMovement().setPosition(rand() % 84 + 8, rand() % 44 + 10);

    for (auto &e : objects) {
        if (e.second)
            if (fruit->getMovement().willColide(0, e.second) == true) {
                replaceFruit();
            }
    }
    fruit->getAnimation().goToSprite(0);
    fruit->getAnimation().setLoop(rand() % 8 == 0);
}

void SnakeScene::killSnake()
{
    removeObject("Snake");
    addObject(this->endMenu);
    removeObject("SnakeFruit");
}

void SnakeScene::launchSnake()
{
    Snake *snake = new Snake(*this);

    snake->setSpeedMode(speedModeValue);
    this->addObject(snake);
    score->setText("Score = 0");
    scoreValue = 0;
    addObject(fruit);
    replaceFruit();
    removeObject("StartMenu");
}

int SnakeScene::getHighScore() const
{
    return this->highScore;
}