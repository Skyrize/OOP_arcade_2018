/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"

class DisplayModule : public IDisplayModule {
    private:
        sf::RenderWindow *window;
        sf::RectangleShape baseSquare = sf::RectangleShape(sf::Vector2f(16, 16));
        std::string _name = "SFML";

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
        void drawShape(int x, int y, std::vector<std::vector<int> >);
        
        std::map<Input, bool> catchInput();
};

#endif /* !SFML_HPP_ */
