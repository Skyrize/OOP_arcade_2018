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
		~StartPannel() = default;

		virtual void display(IDisplayModule *display);

	protected:
		Text *text1;
		Text *text2;
		Text *text3;
		Text *text4;
		Text *text5;
		Text *text6;
		Text *text7;
		Text *text8;
	private:
};

#endif /* !STARTPANNEL_HPP_ */