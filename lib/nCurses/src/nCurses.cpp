/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** nCurses
*/

#include "nCurses.hpp"

void DisplayModule::init()
{
    auto start = std::chrono::steady_clock::now();

    _clock = start;
    initscr();
    curs_set(0);
	noecho();
    cbreak();
    _win = newwin(0, 0, 0, 0);
    use_default_colors();
    nodelay(_win, TRUE);
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
    wclear(_win);
	delwin(_win);
    endwin();
}

void DisplayModule::display()
{
    if (!_isOpen)
        return;
    wrefresh(_win);
}

void DisplayModule::clear()
{
    if (!_isOpen)
        return;
    wclear(_win);
}

void DisplayModule::drawText(int x, int y, const std::string &name) const
{
    if (!_isOpen)
        return;
    mvwprintw(_win, y, x, name.c_str());
}

void DisplayModule::drawShape(int x, int y, std::vector<std::vector<Color> > vec)
{
    int tmp = 0;

    if (!_isOpen)
        return;
    x *= 2;
    tmp = x;
    for (auto &i : vec) {
        for (auto &j : i) {
            if (j == NONE) {
                x += 2;
                continue;
            }
            wattron(_win, COLOR_PAIR(j) | A_STANDOUT);
            mvwprintw(_win, y, x, "  ");
            wattroff(_win, COLOR_PAIR(j) | A_STANDOUT);
            x += 2;
        }
        y += 1;
        x = tmp;
    }
}

std::map<Input, bool> DisplayModule::catchInput()
{
    int key = 0;
    std::map<Input, bool> map;

    if (!_isOpen)
        return map;
    while (1) {
        key = wgetch(_win);
        if (key == ERR)
            break;
        for (auto i: nCursesKeys) {
            if (i.second == key)
                map[i.first] = true;
        }
    }
    return map;
}

float DisplayModule::getTime()
{
    auto end = std::chrono::steady_clock::now();
    auto start = _clock;

    if (!_isOpen)
        return 0;
    return double(double(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 1000000);
}