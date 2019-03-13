/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Projectile
*/

#ifndef PROJECTILE_HPP_
    #define PROJECTILE_HPP_

#include "Object.hpp"
#include "Invader.hpp"
#include "Scene.hpp"

class Invader;

class Projectile : public Object {
	public:
		Projectile(Invader &parent, const std::pair<float, float> &speed, const std::pair<float, float> &position);
		~Projectile();


		virtual float update(IDisplayModule *display, std::map<std::string, Object *> &objects);
		virtual void hitEvent(Object *other);

		virtual int getId();

	protected:
		Invader &parent;
		Scene &space;
		float lifetime;
		float damages;

	private:
};

#endif /* !PROJECTILE_HPP_ */

