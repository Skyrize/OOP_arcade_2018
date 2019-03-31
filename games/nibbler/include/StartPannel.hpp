/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** StartPannel
*/

#ifndef STARTPANNEL_HPP_
    #define STARTPANNEL_HPP_

#include "Object.hpp"
#include "Text.hpp"

class StartPannel : public Object {
	public:
		StartPannel();
		~StartPannel();

		virtual void display(IDisplayModule *display);

	protected:
		std::vector<Text *> texts;
	private:
};

#endif /* !STARTPANNEL_HPP_ */