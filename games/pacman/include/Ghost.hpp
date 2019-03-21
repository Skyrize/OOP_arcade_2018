/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ghost
*/

#ifndef GHOST_HPP_
    #define GHOST_HPP_

#include "Object.hpp"
#include "PacmanScene.hpp"

class Ghost : public Object {

	typedef enum {
		NORMAL,
        BEAST,
		AFFRAID,
	} state_t;

	public:
		Ghost(const std::string &name, Sprite sprite, Scene *parent, const std::pair<float, float> &position = {0.0, 0.0});
		~Ghost();
        void setSpeed(float speed) { _speed = speed; };
        void hitEvent(Object *other) override;
        float update(IDisplayModule *display, std::map<std::string, Object *> &objects) override;

    private:
        int up();
        int down();
        int left();
        int right();
        int callDirectionHandler(int direction);

        state_t _state = NORMAL;
        float _speed = 10;
        Scene *_parent = nullptr;
};

#endif /* !GHOST_HPP_ */
