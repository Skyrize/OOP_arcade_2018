/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Invader
*/

#ifndef INVADER_HPP_
    #define INVADER_HPP_

#include "Object.hpp"
#include "Projectile.hpp"
#include "Scene.hpp"

class Invader : public Object{
    class ShootComponent;

	public:
		Invader(Scene &parent, const std::pair<float, float> &pos);
		~Invader();

        virtual void manageEvents(std::map<Input, bool> &inputs);
        virtual float update(IDisplayModule *display, std::map<std::string, Object *> &objects);
        virtual ShootComponent &getGun();
        virtual Scene &getParent();
	protected:
        Scene &parent;

        class ShootComponent {
            protected:
                Invader &parent;
                bool infiniteAmmo;
                bool hasFired = false;
                int maxAmmo;
                int actualAmmo;

                float ammoLifetime;
                float ammoSpeed;

                float fireTimer = 0;
                float fireRate;

                float reloadTimer = 0;
                float reloadTime;

                float damages;

            public:
                ShootComponent(Invader &parent, const bool &infiniteAmmo, const float &ammoLifetime, const float &ammoSpeed, const float &fireRate, const float &reloadTime, const float &damages);
                ShootComponent(Invader &parent, const float &maxAmmo, const float &ammoLifetime, const float &ammoSpeed, const float &fireRate, const float &reloadTime, const float &damages);
                ~ShootComponent() = default;

                void shoot(const std::pair<float, float> &speed);
                void reload();

                bool hasInfiniteAmmo();
                bool hasShot();
                void setHasShot(const bool &state);
                int getActualAmmo();
                int getMaxAmmo();
                float getFireRate();
                float getFireTimer();
                void setFireTimer(const float &time);
                float getReloadTime();
                float getDamages();
                float getLifeTime();
                float getAmmoSpeed();

        } gun;

	private:
};

#endif /* !INVADER_HPP_ */
