/*
** EPITECH PROJECT, 2040
** OOP_arcade_2040
** File description:
** MainMenuScene.cpp
*/

#include "MainMenuScene.hpp"
#include "Sprites.hpp"
#include "Invader.hpp"
#include "BackButton.hpp"
#include "NextButton.hpp"
#include "MainButton.hpp"
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

MainMenuScene::MainMenuScene()
: Scene("MainMenuScene", none)
{
    //addObject(new Object("BorderLeft", verticalBorderSprite))->getMovement().setBlocking(true);
    //addObject(new Object("BorderRight", verticalBorderSprite, std::pair<float, float>{99, 0}))->getMovement().setBlocking(true);
    //addObject(new Object("BorderTop", horizontalBorderSprite))->getMovement().setBlocking(true);
    //addObject(new Object("BorderBot", horizontalBorderSprite, std::pair<float, float>{0, 56}))->getMovement().setBlocking(true);
    addObject(new Invader(*this, std::pair<float, float>{30, 30}));


	this->pannels.push_back(new Scene("mainPannel", none));
    pannels[0]->addObject(new MainButton(*this, "mainPannel-MainButton", std::pair<float, float>{34, 6}));
	this->pannels.push_back(new Scene("namePannel", none));
    pannels[1]->addObject(new BackButton(*this, "namePannel-BackButton", std::pair<float, float>{10, 10}));
    pannels[1]->addObject(new NextButton(*this, "namePannel-NextButton", std::pair<float, float>{80, 10}));
	this->pannels.push_back(new Scene("menuPannel", none));
    pannels[2]->addObject(new BackButton(*this, "menuPannel-BackButton", std::pair<float, float>{10, 10}));
    pannels[2]->addObject(new NextButton(*this, "menuPannel-NextButton", std::pair<float, float>{80, 10}));
	this->pannels.push_back(new Scene("scorePannel", none));
    pannels[3]->addObject(new BackButton(*this, "scorePannel-ScoreButton", std::pair<float, float>{10, 10}));
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

void MainMenuScene::previousPannel()
{
    if (this->actualPannel != 0) {
        this->actualPannel--;
    }
    objects["SpaceInvader"]->getAnimation().setAnimationSpeed(0.4);
}

void MainMenuScene::nextPannel()
{
    if (this->actualPannel != pannels.size() - 1) {
        this->actualPannel++;
    }
    objects["SpaceInvader"]->getAnimation().setAnimationSpeed(0.4);
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