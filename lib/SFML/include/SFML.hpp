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

        virtual void init();
        virtual void stop();
        virtual const std::string &getName() const { return _name; };

        bool isOpen();
        void display();

        void drawText(int x, int y, std::string name) const;
        void drawShape(int x, int y, std::vector<std::vector<int> >) const;
        
        std::map<Input, bool> catchInput();
    
    private:
        const std::string &_name = "SFML";
};

#endif /* !SFML_HPP_ */
