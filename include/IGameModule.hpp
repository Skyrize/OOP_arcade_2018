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

        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
        
        virtual void run(IDisplayModule *library) = 0;
}

#endif /* IGAMEMODULE_HPP_ */
