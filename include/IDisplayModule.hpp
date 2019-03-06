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

#include "Color.hpp"
#include "Input.hpp"

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;

        virtual bool isOpen() = 0;
        virtual void display() = 0;

        virtual void drawText(int x, int y, const std::string &str) const = 0;
        virtual void drawShape(int x, int y, std::vector< std::vector<int> > shape) const = 0;
        
        virtual std::map<Input, bool> catchInput() = 0;
};

#endif /* IDISPLAYMODULE_HPP_ */
