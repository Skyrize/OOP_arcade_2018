/*
** EPITECH PROJECT, 2040
** OOP_arcade_2040
** File description:
** MainMenuScene.cpp
*/

#include "MainMenuScene.hpp"
#include "Sprites.hpp"
#include <iostream>

MainMenuScene::MainMenuScene()
: Scene("MainMenuScene", sprite_empty)
{
    std::cout << "scene created" << std::endl;
    Object *test = this->addObject("test", pacmanSheet);
    test->getAnimation().setLoop(true);
    test->getAnimation().setAnimationSpeed(0.2);
    test->getMovement().setfreeMoving(true);
    test->getMovement().setBlocking(true);

    Object *testcouille = this->addObject("testcouille", pacmanSheet, std::pair<float, float>{10.0, 0.0});
    testcouille->getAnimation().setAnimationSpeed(0.2);
    testcouille->getAnimation().setLoop(true);
    //testcouille->getMovement().setfreeMoving(true);
    testcouille->getMovement().setDestination(std::pair<float, float>{60.0, 0.0}, 3);
    testcouille->getMovement().setBlocking(true);

    Object *test2 = this->addObject("test2", sheet, std::pair<float, float>{2.0, 10.0});
    test2->getMovement().setBlocking(true);
    test2->getAnimation().setLoop(true);
    test2->getAnimation().setAnimationSpeed(0.2);
    Object *test21 = this->addObject("test3", sheet, std::pair<float, float>{13.1, 10.0});
    test21->getMovement().setBlocking(true);
    test21->getAnimation().setLoop(true);
    test21->getAnimation().setAnimationSpeed(0.2);
    Object *test211 = this->addObject("test4", sheet, std::pair<float, float>{26.0, 10.0});
    test211->getMovement().setBlocking(true);
    test211->getAnimation().setLoop(true);
    test211->getAnimation().setAnimationSpeed(0.2);
    Object *test22 = this->addObject("test5", sheet, std::pair<float, float>{40.0, 10.0});
    test22->getMovement().setBlocking(true);
    test22->getAnimation().setLoop(true);
    test22->getAnimation().setAnimationSpeed(0.2);
    Object *test222 = this->addObject("test6", sheet, std::pair<float, float>{60.0, 10.0});
    test222->getMovement().setBlocking(true);
    test222->getAnimation().setLoop(true);
    test222->getAnimation().setAnimationSpeed(0.2);
    Object *test23 = this->addObject("test7", sheet, std::pair<float, float>{85.0, 10.0});
    test23->getMovement().setBlocking(true);
    test23->getAnimation().setLoop(true);
    test23->getAnimation().setAnimationSpeed(0.2);
    Object *test233 = this->addObject("test8", sheet, std::pair<float, float>{100.0, 10.0});
    test233->getMovement().setBlocking(true);
    test233->getAnimation().setLoop(true);
    test233->getAnimation().setAnimationSpeed(0.2);
    Object *test24 = this->addObject("test21", sheet, std::pair<float, float>{2.0, 20.0});
    test24->getMovement().setBlocking(true);
    test24->getAnimation().setLoop(true);
    test24->getAnimation().setAnimationSpeed(0.2);
    Object *test244 = this->addObject("test31", sheet, std::pair<float, float>{13.1, 20.0});
    test244->getMovement().setBlocking(true);
    test244->getAnimation().setLoop(true);
    test244->getAnimation().setAnimationSpeed(0.2);
    Object *test2444 = this->addObject("test41", sheet, std::pair<float, float>{26.0, 20.0});
    test2444->getMovement().setBlocking(true);
    test2444->getAnimation().setLoop(true);
    test2444->getAnimation().setAnimationSpeed(0.2);
    Object *test2555 = this->addObject("test51", sheet, std::pair<float, float>{40.0, 20.0});
    test2555->getMovement().setBlocking(true);
    test2555->getAnimation().setLoop(true);
    test2555->getAnimation().setAnimationSpeed(0.2);
    Object *test2666 = this->addObject("test61", sheet, std::pair<float, float>{60.0, 20.0});
    test2666->getMovement().setBlocking(true);
    test2666->getAnimation().setLoop(true);
    test2666->getAnimation().setAnimationSpeed(0.2);
    Object *test25 = this->addObject("test71", sheet, std::pair<float, float>{85.0, 20.0});
    test25->getMovement().setBlocking(true);
    test25->getAnimation().setLoop(true);
    test25->getAnimation().setAnimationSpeed(0.2);
    Object *test255 = this->addObject("test81", sheet, std::pair<float, float>{100.0, 20.0});
    test255->getMovement().setBlocking(true);
    test255->getAnimation().setLoop(true);
    test255->getAnimation().setAnimationSpeed(0.2);
    Object *test26 = this->addObject("test22", sheet, std::pair<float, float>{2.0, 30.0});
    test26->getMovement().setBlocking(true);
    test26->getAnimation().setLoop(true);
    test26->getAnimation().setAnimationSpeed(0.2);
    Object *test2z = this->addObject("test23", sheet, std::pair<float, float>{2.0, 40.0});
    test2z->getMovement().setBlocking(true);
    test2z->getAnimation().setLoop(true);
    test2z->getAnimation().setAnimationSpeed(0.2);
    Object *test2e = this->addObject("test32", sheet, std::pair<float, float>{13.1, 30.0});
    test2e->getMovement().setBlocking(true);
    test2e->getAnimation().setLoop(true);
    test2e->getAnimation().setAnimationSpeed(0.2);
    Object *test2a = this->addObject("test33", sheet, std::pair<float, float>{13.1, 40.0});
    test2a->getMovement().setBlocking(true);
    test2a->getAnimation().setLoop(true);
    test2a->getAnimation().setAnimationSpeed(0.2);
    Object *test2d = this->addObject("test42", sheet, std::pair<float, float>{26.0, 30.0});
    test2d->getMovement().setBlocking(true);
    test2d->getAnimation().setLoop(true);
    test2d->getAnimation().setAnimationSpeed(0.2);
    Object *test2c = this->addObject("test43", sheet, std::pair<float, float>{26.0, 40.0});
    test2c->getMovement().setBlocking(true);
    test2c->getAnimation().setLoop(true);
    test2c->getAnimation().setAnimationSpeed(0.2);
    Object *test2x = this->addObject("test52", sheet, std::pair<float, float>{40.0, 30.0});
    test2x->getMovement().setBlocking(true);
    test2x->getAnimation().setLoop(true);
    test2x->getAnimation().setAnimationSpeed(0.2);
    Object *test2f = this->addObject("test53", sheet, std::pair<float, float>{40.0, 40.0});
    test2f->getMovement().setBlocking(true);
    test2f->getAnimation().setLoop(true);
    test2f->getAnimation().setAnimationSpeed(0.2);
    Object *test2g = this->addObject("test62", sheet, std::pair<float, float>{60.0, 30.0});
    test2g->getMovement().setBlocking(true);
    test2g->getAnimation().setLoop(true);
    test2g->getAnimation().setAnimationSpeed(0.2);
    Object *test2b = this->addObject("test63", sheet, std::pair<float, float>{60.0, 40.0});
    test2b->getMovement().setBlocking(true);
    test2b->getAnimation().setLoop(true);
    test2b->getAnimation().setAnimationSpeed(0.2);
    Object *test2h = this->addObject("test72", sheet, std::pair<float, float>{85.0, 30.0});
    test2h->getMovement().setBlocking(true);
    test2h->getAnimation().setLoop(true);
    test2h->getAnimation().setAnimationSpeed(0.2);
    Object *test2j = this->addObject("test73", sheet, std::pair<float, float>{85.0, 40.0});
    test2j->getMovement().setBlocking(true);
    test2j->getAnimation().setLoop(true);
    test2j->getAnimation().setAnimationSpeed(0.2);
    Object *test2n= this->addObject("test82", sheet, std::pair<float, float>{100.0, 30.0});
    test2n->getMovement().setBlocking(true);
    test2n->getAnimation().setLoop(true);
    test2n->getAnimation().setAnimationSpeed(0.2);
    Object *test2k = this->addObject("test83", sheet, std::pair<float, float>{100.0, 40.0});
    test2k->getMovement().setBlocking(true);
    test2k->getAnimation().setLoop(true);
    test2k->getAnimation().setAnimationSpeed(0.2);

    std::cout << "CONSTRUCTED MAINMENUSCENE\n";
}

MainMenuScene::~MainMenuScene()
{
    std::cout << "scene destroyed" << std::endl;
}

void MainMenuScene::manageEvents(std::map<Input, bool> &inputs)
{
    Object::MovementComponent &test = objects["test"]->getMovement();
    if (inputs[Input::A_KEY] == true) {
        objects["test"]->getAnimation().changeSpriteSheet(pacmanSheet2);
        objects["testcouille"]->getAnimation().changeSpriteSheet(pacmanSheet2);
    }
    if (inputs[Input::Z_KEY] == true || inputs[Input::Q_KEY] == true || 
    inputs[Input::S_KEY] == true || inputs[Input::D_KEY] == true) {
        if (inputs[Input::Z_KEY] == true)
            test.setSpeed(test.getSpeed().first, -40);
        else if (inputs[Input::S_KEY] == true)
            test.setSpeed(test.getSpeed().first, 40);
        else
            test.setSpeed(test.getSpeed().first, 0);
        if (inputs[Input::Q_KEY] == true)
            test.setSpeed(-40, test.getSpeed().second);
        else if (inputs[Input::D_KEY] == true)
            test.setSpeed(40, test.getSpeed().second);
        else
            test.setSpeed(0, test.getSpeed().second);
    } else {
        test.setSpeed(0, 0);
    }
    
}