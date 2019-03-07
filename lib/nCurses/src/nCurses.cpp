/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** nCurses
*/

#include "nCurses.hpp"

void DisplayModule::init()
{
    initscr();
    curs_set(0);
	noecho();
    keypad(stdscr, TRUE);
    _isOpen = true;
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void DisplayModule::stop()
{
    _isOpen = false;
    erase();
	endwin();
}

void DisplayModule::display()
{
    refresh();
}

void DisplayModule::clear()
{
    clear();
}

void DisplayModule::drawText(int x, int y, const std::string &name) const
{
    mvprintw(y, x, name.c_str());
}

void DisplayModule::drawShape(int x, int y, std::vector<std::vector<Color> > vec) const
{
    for (auto &i : vec) {
        for (auto &j : i) {
            if (j == NONE) {
                x += 2;
                continue;
            }
            attron(COLOR_PAIR(j) | A_STANDOUT);
            mvprintw(y, x, "  ");
            attroff(COLOR_PAIR(j) | A_STANDOUT);
            x += 2;
        }
        y += 1;
    }
}

std::map<Input, bool> DisplayModule::catchInput()
{
    int key = 0;
    std::map<Input, bool> map;

    while (1) {
        timeout(1);
        key = getch();
        if (key == ERR)
            break;
        if (key == ' ')
            map[SPACE_KEY] = true;
    }
    return map;
}