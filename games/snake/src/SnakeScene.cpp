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

static Sprite fruitSprite {
    {RED},
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
    score = new Text("Score", "Score = 0", 16, WHITE, none, std::pair<float, float>{7, 2});
    endMenu = new EndPannel(this->scoreValue);
    startMenu = new StartPannel();
    fruit = new Object("Fruit", fruitSprite);

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
    if (objects["StartMenu"]) {
        if (inputs[A_KEY] == true) {

        } else if (inputs[E_KEY] == true) {

        }
    }
}

void SnakeScene::eventFruitEaten()
{
    for (auto &e : objects) {
        if (e.second) {
            e.second->getAnimation().setAnimationSpeed(0.2);
            e.second->getAnimation().setNbLoop(3);
        }
    }
    replaceFruit();
    addPoints();
}

void SnakeScene::addPoints()
{
    scoreValue += 10;
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
}

void SnakeScene::killSnake()
{
    removeObject("Snake");
    addObject(this->endMenu);
    removeObject("Fruit");
}

void SnakeScene::launchSnake()
{
    this->addObject(new Snake(*this));
    score->setText("Score = 0");
    scoreValue = 0;
    addObject(fruit);
    replaceFruit();
    removeObject("StartMenu");
}