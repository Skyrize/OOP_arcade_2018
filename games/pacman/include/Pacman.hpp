/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

#include "Object.hpp"
#include "PacmanScene.hpp"

typedef struct beastMode_s {
    int ghostKilled = 0;
    float lifeTime = 0;
} beastMode_t;

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
		BEASTMODE,
		AFFRAID,
	} state_t;

	public:
		Pacman(Scene *parent);
		~Pacman();
		void manageEvents(std::map<Input, bool> &inputs) override;
		float update(IDisplayModule *display, std::map<std::string, Object *> &objects) override;
		void hitEvent(Object *other) override;
		void setState(state_t state) { _state = state; };
		bool isAlive() { return _alive; };
		float getSpeed() const { return _speed; };
        void setSpeed(float speed) { _speed = speed; };

	private:
		void up();
		void down();
		void left();
		void right();

		Scene *_parent = nullptr;
		direction_t _buffer = NONE;
		state_t _state = NORMAL;
		beastMode_t _beastMode;
		float _speed = 10;
		bool _alive = true;
		
};

#endif /* !PACMAN_HPP_ */
