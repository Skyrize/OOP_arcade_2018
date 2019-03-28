/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IDisplayModule.hpp
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <string>
#include <vector>
#include <map>

#include "Colors.hpp"
#include "Input.hpp"

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
        virtual std::map<Input, bool> catchInput() = 0;
        
        virtual void playMusic(std::string) = 0;
        virtual void stopCurrentMusic() = 0;

        virtual bool isOpen() = 0;
        virtual void clear() = 0;

        virtual void drawText(int x, int y, const std::string &str, int fontSize, Color color) = 0;
        virtual void drawShape(int x, int y, std::vector< std::vector<Color> > shape) = 0;
        
        virtual float getTime() = 0;
        virtual void restartTime() = 0;
        virtual void display() = 0;
};

#endif /* IDISPLAYMODULE_HPP_ */
