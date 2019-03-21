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

	typedef enum {
		NORMAL,
		BESTMODE,
		AFFRAID,
	} state_t;

	public:
		Pacman(Scene *parent);
		~Pacman();
		void manageEvents(std::map<Input, bool> &inputs) override;
		float update(IDisplayModule *display, std::map<std::string, Object *> &objects) override;
		void hitEvent(Object *other) override;
		void setState(state_t state) { _state = state; };

	private:
		void up();
		void down();
		void left();
		void right();

		Scene *_parent = nullptr;
		direction_t _buffer = NONE;
		state_t _state = NORMAL;
		float _speed = 10;
		
};

#endif /* !PACMAN_HPP_ */
