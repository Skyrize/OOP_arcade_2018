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
        std::cout << "Usage : Please enter a library path" << std::endl;
        return (0);
    }
    try {
        Arcade arcade(av[1]);
        srand(time(NULL));
        arcade.launch();
    } catch (std::exception &e) {
        std::cerr << "An error occured. Please restart the Arcade" << std::endl;
        return 84;
    }
    return 0;
}