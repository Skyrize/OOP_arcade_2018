/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

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
        const std::string &_name = "SFML";
};

#endif /* !SFML_HPP_ */
