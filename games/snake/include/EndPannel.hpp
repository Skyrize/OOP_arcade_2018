/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** EndPannel
*/

#ifndef ENDPANNEL_HPP_
    #define ENDPANNEL_HPP_

#include "Object.hpp"
#include "Text.hpp"

class EndPannel : public Object {
	public:
		EndPannel(const int &scoreRef);
		~EndPannel() = default;

		virtual void display(IDisplayModule *display);
	protected:
        const int &scoreRef;
		Text *text1;
		Text *text2;
		Text *text3;
	private:
};

#endif /* !ENDPANNEL_HPP_ */
