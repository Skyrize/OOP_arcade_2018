/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <iostream>
#include <vector>

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
        virtual void drawText(int x, int y, std::string name) const = 0;
        virtual void drawShape(int x, int y, std::vector<std::vector<int>>) const = 0;
        virtual bool isKeyPressed(int key);

};

#endif /* !IDISPLAYMODULE_HPP_ */
