/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGameModule.hpp
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <string>

#include "Color.hpp"
#include "IDisplayModule.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;

        virtual void init(IDisplayModule *library) = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;

        virtual void run() = 0;
        virtual void changeDisplayModule(IDisplayModule *lib) = 0;
};

#endif /* IGAMEMODULE_HPP_ */
