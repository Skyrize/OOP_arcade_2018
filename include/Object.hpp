/*
 ** EPITECH PROJECT, 2019
 ** ESH
 ** File description: Created on: 25 janv. 2019
 ** Object.hpp
 */

#ifndef SRC_OBJECT_HPP_
#define SRC_OBJECT_HPP_

#include <vector>
#include <utility>
#include "Colors.hpp"
#include "IDisplayModule.hpp"

#define SPEED_X this->speed.first
#define SPEED_Y this->speed.second

#define POS_X this->position.first
#define POS_Y this->position.second

#define DEST_X this->destination.first
#define DEST_Y this->destination.second

#define GET_X(pair) pair.first
#define GET_Y(pair) pair.second

typedef std::vector<std::vector<Color>> Sprite;
typedef std::vector<Sprite> SpriteSheet;

class Object {
	public:
		class MovementComponent; /*predefine*/
		class AnimationComponent;
		Object(const std::string &name, SpriteSheet &spriteSheet, std::pair<float, float> position = {0.0, 0.0});
		Object(const std::string &name, Sprite &sprite, std::pair<float, float> position = {0.0, 0.0});
		virtual ~Object();

		virtual void display(IDisplayModule *display);
		virtual float update(IDisplayModule *display, std::map<std::string, Object *> &objects);
		virtual MovementComponent &getMovement();
		virtual AnimationComponent &getAnimation();
		virtual const std::string &getName() const;
		virtual void manageEvents(std::map<Input, bool> &inputs);
		virtual void hitEvent(Object *other);

	protected:
		std::string name;
		float oldTime = 0;

		class AnimationComponent {
			public:
				AnimationComponent(Object &parent, SpriteSheet &spriteSheet);
				AnimationComponent(Object &parent, Sprite &sprite);
				~AnimationComponent() = default;

				void animate(float delta);
				const Sprite &getSprite() const;
				const SpriteSheet &getSpriteSheet() const;
				const std::pair<float, float> &getSize() const;
				bool isAnimated() const;
				void setAnimationSpeed(const float &speed);
				void setNbLoop(const float &nbLoop);
				void setLoop(const bool &state);
				void goNextSprite();
				void goToSprite(const size_t &index);
				void changeSpriteSheet(SpriteSheet &spriteSheet);
				void changeSpriteSheet(Sprite &sprite);

			protected:
				size_t actual = 0;
				float animationSpeed = 0;
				float remainingTime = 0;
				size_t nbLoop = 0;
				bool infiniteLoop = false;
				Object &parent;
				SpriteSheet spriteSheet;
				std::pair<float, float> size;

				void setSize();

		} sprite;

		class MovementComponent {
			public:
				MovementComponent(Object &parent);
				~MovementComponent() = default;

				void move(const float &delta, std::map<std::string, Object *> &objects);
		        bool hasReachDuration(float delta);
				bool isMoving() const;
				bool isFreeMoving() const;
				bool isBlocking() const;
				void setSpeed(const float &x, const float &y);
				void setPosition(const float &x, const float &y);
		        void setfreeMoving(const bool &state);
		        void setBlocking(const bool &state);
		        void setDestination(const std::pair<float, float> &newDest, const float &timeToReach);
				const std::pair<float, float> &getPosition() const;
				const std::pair<float, float> &getSpeed() const;
				const std::pair<float, float> &getDestination() const;
				bool willColide(float delta, Object *other) const;

			protected:
				Object &parent;

		        bool freeMoving = false;
				bool blocking = false;
		        float remainingTimeMoving = 0;

		        std::pair<float, float> speed{0.0, 0.0};
		        std::pair<float, float> position{0.0, 0.0};
				std::pair<float, float> destination{0.0, 0.0};

		} movement;
};

#endif /* SRC_OBJECT_HPP_ */
