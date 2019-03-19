/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

#include "Object.hpp"
#include "Scene.hpp"

class Pacman : public Object {

	typedef enum {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		NONE,
	}  direction_t;

	public:
		Pacman(Scene *scene);
		~Pacman();
		void manageEvents(std::map<Input, bool> &inputs) override;

	private:
		void up();
		void down();
		void left();
		void right();
		
		float _speed = 10;
		direction_t buffer = NONE;
		Scene *scene;
};

#endif /* !PACMAN_HPP_ */
