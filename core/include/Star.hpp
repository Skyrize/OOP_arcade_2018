/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Star
*/

#ifndef STAR_HPP_
    #define STAR_HPP_

#include "Object.hpp"

class Star : public Object {
	public:
		Star(const std::string &name);
		~Star() = default;

        void respawn();
		virtual void eventReachedDestination();
	protected:
	private:
};

#endif /* !STAR_HPP_ */