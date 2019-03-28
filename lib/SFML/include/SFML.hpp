/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#define SFML_NO_DEPRECATED_WARNINGS

#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"

class DisplayModule : public IDisplayModule {
    private:
        sf::RenderWindow *window;
        sf::RectangleShape baseSquare = sf::RectangleShape(sf::Vector2f(16, 16));
        std::string _name = "SFML";
        sf::Clock clock;
        sf::Time timer;
        sf::Font font;
        sf::Text text;

	public:
		DisplayModule();
		virtual ~DisplayModule();

        void init();
        void stop();
        const std::string &getName() const { return _name; };

        void playMusic(std::string musicName);
        void stopCurrentMusic();

        bool isOpen();
        void clear();
        void display();

        void drawText(int x, int y, const std::string &name, int fontSize, Color color);
        void drawShape(int x, int y, std::vector<std::vector<Color> >);
        
        float getTime();
        void restartTime();
        std::map<Input, bool> catchInput();
};

#endif /* !SFML_HPP_ */
