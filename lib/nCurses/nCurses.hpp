/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** nCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "IDisplayModule.hpp"

class DisplayModule : public IDisplayModule {
	public:
		DisplayModule() {};
		~DisplayModule() {};
        void init();
        void stop();
        const std::string &getName() const { return _name; };
        void drawText(int x, int y, std::string name) const;
        void drawShape(int x, int y, std::vector<std::vector<int>>) const;
        bool isKeyPressed(int key);

    private:
        const std::string &_name = "nCurses";
};

#endif /* !NCURSES_HPP_ */
