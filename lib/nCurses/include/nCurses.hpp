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
		DisplayModule() = default;
		virtual ~DisplayModule() = default;

        void init();
        void stop();
        const std::string &getName() const { return _name; };

        bool isOpen();
        void display();

        void drawText(int x, int y, const std::string &name) const;
        void drawShape(int x, int y, std::vector<std::vector<int> >) const;
        
        std::map<Input, bool> catchInput();
    
    private:
        std::string _name = "nCurses";
};

#endif /* !NCURSES_HPP_ */
