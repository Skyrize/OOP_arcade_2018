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

class Snake : public Object {
	public:
		Snake();
		~Snake();

		virtual void manageEvents(std::map<Input, bool> &inputs);
	protected:
        SnakeTail tail;
        std::vector<SnakePart *> parts;
	private:
};

#endif /* !SNAKE_HPP_ */
