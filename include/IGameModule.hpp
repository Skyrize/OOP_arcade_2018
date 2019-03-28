/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGameModule.hpp
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <string>

#include "Colors.hpp"
#include "IDisplayModule.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;

        virtual void init(const std::string &playerName, const int &highScore) = 0;
        virtual void stop() = 0;
        virtual void restart() const = 0;
        virtual void run(IDisplayModule *library, std::map<Input, bool> &inputs) = 0;
        virtual const std::string &getName() const = 0;
        virtual int getHighScore() const = 0;
};

#endif /* IGAMEMODULE_HPP_ */
