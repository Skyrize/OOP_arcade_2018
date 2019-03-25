/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Teleporter
*/

#ifndef TELEPORTER_HPP_
    #define TELEPORTER_HPP_

#include "Object.hpp"

class Teleporter : public Object {
	public:
		Teleporter(const std::string &name, Sprite &sprite,
            const std::pair<float, float> &teleportPosition,
            const std::pair<float, float> &position = {0.0, 0.0})
            : Object(name, sprite, position), _teleportPosition(teleportPosition) {
                this->getMovement().setBlocking(false);
            };
		~Teleporter() = default;
        void hitEvent(Object *other) override
        {
            other->getMovement().setPosition(_teleportPosition.first, _teleportPosition.second);
        };
    
    private:
        std::pair<float, float> _teleportPosition;
};

#endif /* !TELEPORTER_HPP_ */
