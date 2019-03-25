/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

#include "Object.hpp"
#include "SnakeScene.hpp"

class SnakePart;

class Snake : public Object {
	public:
		Snake(SnakeScene &parent);
		~Snake();

		virtual void manageEvents(std::map<Input, bool> &inputs);
		virtual float update(IDisplayModule *display, std::map<std::string, Object *> &objects);
		virtual void hitEvent(Object *other);

		void left();
		void right();
		void up();
		void down();
		void addPart();
		void eatFruit();
		void moveParts();

		size_t getNbParts();

		void die(float delta);

		void setSpeed(int newSpeed);
		void setAnimation(float speed, int nbLoop);
		void setSprite(int index);
		void setSpeedMode(bool state);
		//bool fullyInBlock();

	protected:
		std::pair<float, float> oldPos;
		SnakeScene &parent;
        Object *tail;
        std::vector<Object *> body;
		int actualDirection = 0;
		int speed = 20;
		float boostTimer = 0;
		float boostCooldown = 0;
		bool isDead = false;

		int boostSpeed = 40;
		int baseSpeed = 20;
		bool speedMode = false;
	private:
};

#endif /* !SNAKE_HPP_ */
