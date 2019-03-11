/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_

class Event {
	protected:
        virtual void start();
        virtual void stop();
        virtual void restart();
        virtual void run() = 0;
	public:
		Event();
		~Event();
};

#endif /* !EVENT_HPP_ */

