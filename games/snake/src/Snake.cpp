/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#include "Snake.hpp"

//Sprite snakeHeadSheet {
//    {
//        {NONE, GREEN, NONE},
//        {GREEN, GREEN, GREEN},
//        {GREEN, YELLOW, GREEN},
//    },
//    {
//        {GREEN,  YELLOW, GREEN},
//        {GREEN, GREEN, GREEN},
//        {NONE,  GREEN, NONE},
//    },
//    {
//        {GREEN,  GREEN, NONE},
//        {YELLOW, GREEN, GREEN},
//        {GREEN,  GREEN, NONE},
//    },
//    {
//        {NONE,  GREEN, GREEN},
//        {GREEN, GREEN, YELLOW},
//        {NONE,  GREEN, GREEN},
//    },
//};

#define SNAKE_UP 0
#define SNAKE_DOWN 1
#define SNAKE_RIGHT 2
#define SNAKE_LEFT 3

#define SPEED_BASE 20
#define SPEED_BOOST 40

#define BOOST_TIMER 1
#define BOOST_CD 1

SpriteSheet snakeHeadSpriteSheet {
    {
        {YELLOW}
    },
    {
        {WHITE}
    }
};

SpriteSheet snakePartSpriteSheet {
    {
        {GREEN}
    },
    {
        {RED}
    }
};

SpriteSheet snakeTailSpriteSheet {
    {
        {CYAN}
    },
    {
        {MAGENTA}
    }
};

Sprite deadPart {
    {WHITE, NONE, WHITE},
    {NONE, NONE, NONE},
    {WHITE, NONE, WHITE},
};

Snake::Snake(SnakeScene &parent)
: Object("Snake", snakeHeadSpriteSheet),
parent(parent)
{
    this->movement.setFreeMoving(true);
    movement.setBlocking(true);
    movement.setPosition(47, 37);

    body.push_back(new Object("SnakePart-" + std::to_string(body.size()), snakePartSpriteSheet, std::pair<float, float>{47, 38}));
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
    body.push_back(new Object("SnakePart-" + std::to_string(body.size()), snakePartSpriteSheet, std::pair<float, float>{47, 39}));
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
    body.push_back(new Object("SnakeTail" + std::to_string(body.size()), snakeTailSpriteSheet, std::pair<float, float>{47, 40}));
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
}

Snake::~Snake()
{
}

float Snake::update(IDisplayModule *display, std::map<std::string, Object *> &objects)
{
    oldPos = movement.getPosition();
    int x = oldPos.first;
    int y = oldPos.second;
    float delta = Object::update(display, objects);

    if (isDead == false) {
        if (x != (int)movement.getPosition().first || y != (int)movement.getPosition().second)
            moveParts();
        if (boostTimer > 0) {
            boostTimer -= delta;
            if (boostTimer <= 0) {
                setAnimation(0, -2);
                setSprite(1);
                setSpeed(SPEED_BASE);
                boostCooldown = BOOST_CD;
                boostTimer = 0;
            }
        } else if (boostCooldown > 0) {
            boostCooldown -= delta;
            if (boostCooldown <= 0) {
                setAnimation(0, -2);
                setSprite(0);
                boostCooldown = 0;
            }
        }
    } else {
        die(delta);
    }
    return delta;
}

void Snake::hitEvent(Object *other)
{
    if (other->getName() == "Fruit") {
        eatFruit();
    } else {
        isDead = true;
        movement.setSpeed(0, 0);
    }
}

void Snake::eatFruit()
{
    parent.eventFruitEaten();
    addPart();
    setAnimation(0, 0);
}

void Snake::die(float delta)
{
    static float start = 0;
    static bool changed = false;

    start += delta;
    if (start >= 0.1) {
        
        if (changed == false) {
            if (body.size() != 0) {
                const std::pair<float, float> &pos = body[body.size() - 1]->getMovement().getPosition();
                body[body.size() - 1]->getMovement().setPosition(GET_X(pos) - 1, GET_Y(pos) - 1);
                body[body.size() - 1]->getAnimation().changeSpriteSheet(deadPart);
                changed = true;
            } else {
                const std::pair<float, float> &pos = this->getMovement().getPosition();
                this->getMovement().setPosition(GET_X(pos) - 1, GET_Y(pos) - 1);
                this->getAnimation().changeSpriteSheet(deadPart);
                changed = true;
            }
        }
        if (start >= 0.2) {
            if (body.size() != 0) {
                parent.removeObject(body[body.size() - 1]->getName());
                body.pop_back();
            } else {
                parent.killSnake();
            }
            start = 0;
            changed = false;
        }
    }
}

void Snake::addPart()
{
    Object *tail = body[body.size() - 1];
    
    body[body.size() - 1] = new Object("SnakePart-" + std::to_string(body.size()), snakePartSpriteSheet, std::pair<float, float>{0, 0});
    body[body.size() - 1]->getMovement().setBlocking(true);
    parent.addObject(body[body.size() - 1]);
    body.push_back(tail);
}

void Snake::moveParts()
{
    if (movement.isMoving() == false)
        return;
    for (int i = body.size() - 1; i != 0; i--) {
        body[i]->getMovement().setPosition(body[i - 1]->getMovement().getPosition().first, body[i - 1]->getMovement().getPosition().second);
    }
    body[0]->getMovement().setPosition(oldPos.first, oldPos.second);
}

size_t Snake::getNbParts()
{
    return body.size();
}

// bool Snake::fullyInBlock()
// {
//     const std::pair<float, float> &pos = movement.getPosition();

//     if ((int)(GET_X(pos) + 1) % 3 == 0 && (int)(GET_Y(pos) - 1) % 3 == 0)
//         return true;
//     return false;
// }

void Snake::up()
{
    if (actualDirection == SNAKE_DOWN)
        return;
    movement.setSpeed(0, -speed);
    actualDirection = SNAKE_UP;
}

void Snake::down()
{
    if (actualDirection == SNAKE_UP)
        return;
    movement.setSpeed(0, speed);
    actualDirection = SNAKE_DOWN;
}

void Snake::left()
{
    if (actualDirection == SNAKE_RIGHT)
        return;
    movement.setSpeed(-speed, 0);
    actualDirection = SNAKE_LEFT;
}

void Snake::right()
{
    if (actualDirection == SNAKE_LEFT)
        return;
    movement.setSpeed(speed, 0);
    actualDirection = SNAKE_RIGHT;
}

void Snake::setSpeed(int newSpeed)
{
    this->speed = newSpeed;
    switch (actualDirection) {
        case SNAKE_UP:
            movement.setSpeed(0, -speed);
            break;
        case SNAKE_DOWN:
            movement.setSpeed(0, speed);
            break;
        case SNAKE_LEFT:
            movement.setSpeed(-speed, 0);
            break;
        case SNAKE_RIGHT:
            movement.setSpeed(speed, 0);
            break;
        default:
            break;
    }
}

void Snake::setAnimation(float speed, int nbLoop)
{
    this->getAnimation().setAnimationSpeed(speed);
    if (nbLoop == -1)
        this->getAnimation().setLoop(true);
    else if (nbLoop == -2)
        this->getAnimation().setLoop(false);
    else
        this->getAnimation().setNbLoop(nbLoop);
    for (auto &e : body) {
        e->getAnimation().setAnimationSpeed(speed);
        if (nbLoop == -1)
            e->getAnimation().setLoop(true);
        else if (nbLoop == -2)
            e->getAnimation().setLoop(false);
        else
            e->getAnimation().setNbLoop(nbLoop);
    }
}

void Snake::setSprite(int index)
{
    this->getAnimation().goToSprite(index);
    for (auto &e : body)
        e->getAnimation().goToSprite(index);
}

void Snake::manageEvents(std::map<Input, bool> &inputs)
{
    if (isDead == false) {
        if (inputs[Input::UP_ARROW_KEY] == true) {
            up();
        } else if (inputs[Input::DOWN_ARROW_KEY] == true) {
            down();
        } else if (inputs[Input::LEFT_ARROW_KEY] == true) {
            left();
        } else if (inputs[Input::RIGHT_ARROW_KEY] == true) {
            right();
        }
        if (inputs[SPACE_KEY] == true && speed == 20 && boostCooldown == 0) {
            setSpeed(40);
            boostTimer = BOOST_TIMER;
            setAnimation(0.2, -1);
        }
    }
}
