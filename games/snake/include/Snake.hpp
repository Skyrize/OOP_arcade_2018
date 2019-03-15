/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

#include "Object.hpp"
#include "SnakePart.hpp"
#include "SnakeTail.hpp"

class SnakePart;

class Snake : public Object {
	public:
		Snake();
		~Snake();

		virtual void manageEvents(std::map<Input, bool> &inputs);

		void left();
		void right();
		void up();
		void down();
		void addPart();
		void eatFruit();
		void moveParts();

		size_t getNbParts();

		bool fullyInBlock();
		void replaceInBlock();

	protected:
        SnakeTail tail;
        std::vector<SnakePart *> parts;
		int actualDirection = 0;
		int speed = 1;
	private:
};

#endif /* !SNAKE_HPP_ */
