/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakePart
*/

#ifndef SNAKEPART_HPP_
    #define SNAKEPART_HPP_

#include "Object.hpp"
#include "Snake.hpp"

class Snake;

class SnakePart : public Object {
	public:
		SnakePart(Snake &head, SnakePart *next, const std::pair<float, float> &position);
		~SnakePart();

		bool fullyInBlock();
		void replaceInBlock();

	protected:
		std::pair<float, float> fullPos;
		Snake &head;
		SnakePart *nextPart;
	private:
};

#endif /* !SNAKEPART_HPP_ */
