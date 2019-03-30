/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakeScene
*/

#include "PacmanScene.hpp"
#include "PacmanSprites.hpp"
#include "EndMenu.hpp"

PacmanScene::PacmanScene()
: Scene("PacmanScene", none)
{
    Object *rightPacMan = this->addObject("PacmanRight", RightBigPacMan, {88, 27});
    Object *leftPacMan = this->addObject("PacmanLeft", LeftBigPacMan, {3, 27});
    
    this->addObject(new Text("PacmanTitle", "PacMan", 100, YELLOW, none, {35, 6}));
    this->addObject(new Text("Info", "Press Enter to Start", 70, WHITE, none, {15, 27}));
    rightPacMan->getAnimation().setLoop(true);
    rightPacMan->getAnimation().setAnimationSpeed(0.1);
    leftPacMan->getAnimation().setLoop(true);
    leftPacMan->getAnimation().setAnimationSpeed(0.1);
}

PacmanScene::~PacmanScene()
{
}

static void initGum(Object *gum)
{
    gum->getMovement().setBlocking(false);
    gum->getAnimation().setAnimationSpeed(0.2);
    gum->getAnimation().setLoop(true);
}

void PacmanScene::initPacGums(void)
{
    Object *gum1 = this->addObject("BigAPacGum1", bigPacGum, {2 * 3, 2 * 3});
    Object *gum2 = this->addObject("BigAPacGum2", bigPacGum, {18 * 3, 2 * 3});
    Object *gum3 = this->addObject("BigAPacGum3", bigPacGum, {5 * 3, 15 * 3});
    Object *gum4 = this->addObject("BigAPacGum4", bigPacGum, {15 * 3, 15 * 3});

    for (int j = 0; j < 19 * 3; j++) {
        for (int i = 0; i < 20 * 3; i++) {
            if ((j == 21 || j == 27 || j == 33)     // Gums out of the area
            && (i < 15 || i > 45))
                continue;
            if (((j == 9 * 3 || j == 10 * 3)        // Box in the Middle
            && i > 8 * 3 && i < 12 * 3)
            || (i == 10 * 3 && j == 8 * 3))
                continue;
            if ((i == 2 * 3 && j == 2 * 3)          // BigPacGums
            || (i == 18 * 3 && j == 2 * 3)
            || (i == 5 * 3 && j == 15 * 3)
            || (i == 15 * 3 && j == 15 * 3))
                continue;
            if (mapSprite[j][i] == NONE && i > 3 && i < 19 * 3
            && i % 3 == 0 && j % 3 == 0)
                this->addObject("APacGum" + std::to_string(i) + std::to_string(j), pacGum, {i, j})->getMovement().setBlocking(false);
        }
    }
    initGum(gum1);
    initGum(gum2);
    initGum(gum3);
    initGum(gum4);
}

void PacmanScene::initGhosts()
{
    this->addObject(new Ghost("ZGhostRed", redGhost, this, {9 * 3, 9 * 3}));
    this->addObject(new Ghost("ZGhostYellow", yellowGhost, this, {10 * 3, 9 * 3}));
    this->addObject(new Ghost("ZGhostCyan", cyanGhost, this, {11 * 3, 9 * 3}));
    this->addObject(new Ghost("ZGhostMagenta", magentaGhost, this, {10 * 3, 10 * 3}));
}

void PacmanScene::initGame()
{
    this->removeAllObjects();
    this->addObject(new Pacman(this));
    this->addObject("PacmanMap", mapSprite)->getMovement().setBlocking(true);
    this->addObject(new Teleporter("Teleporter1", blackSquare, {61, 27}, {-3, 27}));
    this->addObject(new Teleporter("Teleporter2", blackSquare, {-1, 27}, {63, 27})); 
    initPacGums();
    initGhosts();
    this->addObject("Gate", normalGate, {10 * 3, 8 * 3})->getMovement().setBlocking(true);
    this->addObject(new ScorePannel({66, 3}, this));
    _gateSecondsRemaining = 5;
}

void PacmanScene::manageEvents(std::map<Input, bool> &inputs)
{
    if (_restartSecondsRemaining > 0)
        return;
    if (!_startMenu && !_endMenu)
        objects["Pacman"]->manageEvents(inputs);
    if (_startMenu) {
        if (inputs[RETURN_KEY]) {
            _startMenu = false;
            initGame();
        }
    } else if (_endMenu) {
        if (inputs[RETURN_KEY]) {
            _endMenu = false;
            _needToOpen = true;
            _score = 0;
            initGame();
        }
    }
    if (inputs[R_KEY]) {
        _endMenu = false;
        _needToOpen = true;
        _score = 0;
        initGame();
    }
}

void PacmanScene::affraidGhosts()
{
    for (auto &i : this->objects) {
        if (i.first.find("Ghost") != std::string::npos
        && i.second
        && ((Ghost *)i.second)->isAlive()) {
            ((Ghost *)i.second)->affraid();
        }
    }
}

void PacmanScene::unaffraidGhosts()
{
    for (auto &i : this->objects) {
        if (i.first.find("Ghost") != std::string::npos
        && ((Ghost *)i.second)->isAlive()) {
            ((Ghost *)i.second)->unaffraid();
        }
    }
}

static bool collide(std::pair<int, int> pos1, std::pair<int, int> size1,
    std::pair<int, int> pos2, std::pair<int, int> size2)
{
    return pos1.first < pos2.first + size2.first
    && pos1.first + size1.first > pos2.first
    && pos1.second < pos2.second + size2.second
    && pos1.second + size1.second > pos2.second;
}

bool PacmanScene::ghostsInBox()
{
    std::pair<int, int> pos;

    for (auto &i : this->objects) {
        if (i.second)
            pos = (std::pair<int, int>)i.second->getMovement().getPosition();
        else
            continue;
        if (i.first.find("Ghost") != std::string::npos
        && (collide(pos, {3, 3}, {9 * 3, 9 * 3}, {9, 6})
        || collide(pos, {3, 3}, {10 * 3, 8 * 3}, {3, 3}))) {
            return true;
        }
    }
    return false;
}

bool PacmanScene::anyPacGumsLeft()
{
    for (auto &i: objects) {
        if (i.first.find("PacGum") != std::string::npos && i.second)
            return true;
    }
    return false;
}

void PacmanScene::updateGate(float delta)
{
    if (_needToClose == true && !ghostsInBox()) {
        this->addObject("Gate", normalGate, {10 * 3, 8 * 3})->getMovement().setBlocking(true);
        _needToClose = false;
        _needToOpen = false;
    }
    if (getObject("Gate") && _needToOpen) {
        _gateSecondsRemaining -= delta;
        if (_gateSecondsRemaining <= 0) {
            _needToOpen = false;
            _needToClose = true;
            removeObject("Gate");
        } else if (_gateSecondsRemaining <= 2 && !getObject("Gate")->getAnimation().isAnimated()) {
            getObject("Gate")->getAnimation().changeSpriteSheet(animatedGate);
            getObject("Gate")->getAnimation().setAnimationSpeed(0.1);
            getObject("Gate")->getAnimation().setLoop(true);
        }
    }
}

void PacmanScene::updateRestart(float delta)
{
    float oldSpeed = 0;

    (void)delta;
    if (!anyPacGumsLeft()) {
        oldSpeed = ((Pacman *)this->getObject("Pacman"))->getSpeed();
        this->removeAllObjects();
        this->initGame();
        ((Pacman *)this->getObject("Pacman"))->setSpeed(oldSpeed * 1.3);
        for (auto &i: objects) {
            if (i.first.find("Ghost") != std::string::npos)
                ((Ghost *)i.second)->setSpeed(oldSpeed * 1.3);
        }
        _restartSecondsRemaining = 3;
        _needToOpen = true;
    }
}

float PacmanScene::update(IDisplayModule *displays)
{
    float delta = Scene::update(displays);

    if (_startMenu)
        return delta;
    if (_endMenu) {
        ((Scene *)this->getObject("EndMenu"))->update(displays);
        return delta;
    }
    ((Scene *)this->getObject("ScorePannel"))->update(displays);
    if (_restartSecondsRemaining > 0) {
        _restartSecondsRemaining -= delta;
        return delta;
    }
    if (getObject("Pacman") && !((Pacman *)getObject("Pacman"))->isAlive()) {
        this->removeAllObjects();
        this->addObject(new EndMenu(_score));
        _endMenu = true;
        return delta;
    }
    updateRestart(delta);
    updateGate(delta);
    return delta;
}

void PacmanScene::addScore(int score)
{
    _score += score;
    if (_score > _actualHighScore)
        _actualHighScore =_score;
}