/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** libcaca
*/

#ifndef LIBCACA_HPP_
#define LIBCACA_HPP_

#include "IDisplayModule.hpp"

class DisplayModule : public IDisplayModule {
	public:
		DisplayModule() = default;
		virtual ~DisplayModule() = default;
        void init();
        void stop();
        const std::string &getName() const { return _name; };
        void drawText(int x, int y, std::string name) const;
        void drawShape(int x, int y, std::vector<std::vector<int>>) const;
        bool isKeyPressed(int key);
    
    private:
        const std::string &_name = "libcaca";
};

#endif /* !LIBCACA_HPP_ */
