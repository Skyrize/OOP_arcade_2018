/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include <SDL2/SDL.h>
#include "IDisplayModule.hpp"

class DisplayModule : public IDisplayModule {
    private:
        std::string _name = "SDL2";

	public:
		DisplayModule();
		virtual ~DisplayModule();

        void init();
        void stop();
        const std::string &getName() const { return _name; };

        bool isOpen();
        void clear();
        void display();

        void drawText(int x, int y, const std::string &name) const;
        void drawShape(int x, int y, std::vector<std::vector<Color> >) const;
        
        std::map<Input, bool> catchInput();
};

#endif /* !SDL2_HPP_ */
