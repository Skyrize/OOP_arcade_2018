/*
** EPITECH PROJECT, 2019
** snake
** File description:
** SnakePart
*/

#ifndef SNAKEPART_HPP_
    #define SNAKEPART_HPP_

#include "Object.hpp"

class SnakePart : public Object {
	public:
		SnakePart(const std::string &name, const std::pair<float, float> &position);
		~SnakePart();

	protected:
	private:
};

#endif /* !SNAKEPART_HPP_ */
