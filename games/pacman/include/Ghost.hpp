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

    typedef enum {
		NONE = -1,
        UP = 0,
		DOWN = 1,
		LEFT = 2,
		RIGHT = 3,
    } direction_t;

	public:
		Ghost(const std::string &name, Sprite sprite, Scene *parent, const std::pair<float, float> &position = {0.0, 0.0});
		~Ghost();
        float getSpeed() const { return _speed; };
        void setSpeed(float speed) { _speed = speed; };
        void eventHit(Object *other) override;
        float update(IDisplayModule *display, std::map<std::string, Object *> &objects) override;
        void kill();
        void affraid();
        void unaffraid();
        void revive();
        bool isAlive() const { return _alive; };
        state_t getState() { return _state; };

    private:
        int up();
        int down();
        int left();
        int right();
        int callDirectionHandler(int direction);
        void setDestination(direction_t direction);

        state_t _state = NORMAL;
        direction_t _direction = NONE;
        direction_t _reverseDirection = NONE;
        float _speed = 10;
        Scene *_parent = nullptr;
        std::pair<int, int> _destination;
        bool _alive = true;
        Sprite _oldSprite;
        float _oldSpeed;
};

#endif /* !GHOST_HPP_ */
