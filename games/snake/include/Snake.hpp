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


		//bool fullyInBlock();

	protected:
		std::pair<float, float> oldPos;
		SnakeScene &parent;
        Object *tail;
        std::vector<Object *> body;
		int actualDirection = 0;
		int speed = 20;
		bool isDead = false;
	private:
};

#endif /* !SNAKE_HPP_ */
