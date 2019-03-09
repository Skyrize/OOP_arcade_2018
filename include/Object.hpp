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

class Object {
	public:
		class MovementComponent; /*predefine*/
		Object(const std::string &name, std::vector<std::vector<Color> > &sprite, std::pair<float, float> position = {0.0, 0.0});
		virtual ~Object() = default;

		virtual void display(IDisplayModule *display);
		virtual void update(IDisplayModule *display, std::map<std::string, Object *> &objects);
		virtual MovementComponent &getMovement();
		virtual const std::vector<std::vector<Color> > &getSprite() const;
		virtual const std::string &getName() const;
		virtual void manageEvents(IDisplayModule *display, std::map<Input, bool> &inputs);
		virtual const std::pair<float, float> &getSize() const;

	protected:
		std::string name;
		std::vector<std::vector<Color> > sprite;
		std::pair<float, float> size;

		class MovementComponent {
			public:
				MovementComponent(Object &parent): parent(parent) {}
				~MovementComponent() = default;

				void move(float actualTime, std::map<std::string, Object *> &objects);
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
