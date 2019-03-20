/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.cpp
*/

#include <iostream>
#include "Arcade.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage : rentre une lib stp frer" << std::endl;
        return (0);
    }
    Arcade arcade(av[1]);
    srand(time(NULL));
    arcade.launch();
    return 0;
}