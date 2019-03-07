/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Letter.hpp
*/

#ifndef LETTER_H_
#define LETTER_H_

#include <map>

#define A_LETTER    "\
    A    \
   A A   \
  AAAAA  \
 A     A \
A       A"

#define B_LETTER    "\
B  A    \
B A A   \
BAAAAA  \
BAAAAA  \
B     A "

const std::map<char, char *> letters = {
    {'a', },
};

#endif /* LETTER_H_ */