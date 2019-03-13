/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** test_ncurses
*/

#include <ncurses.h>
#include <unistd.h>
// #include <iostream>

int main(void)
{
    initscr();
    curs_set(0);
	noecho();
    // cbreak();
    // use_default_colors();
    // keypad(stdscr, TRUE);
    // nodelay(stdscr, TRUE);
    // start_color();
    // init_pair(0, COLOR_BLACK, COLOR_BLACK);
    // init_pair(1, COLOR_RED, COLOR_BLACK);
    // init_pair(2, COLOR_GREEN, COLOR_BLACK);
    // init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    // init_pair(4, COLOR_BLUE, COLOR_BLACK);
    // init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    // init_pair(6, COLOR_CYAN, COLOR_BLACK);
    // init_pair(7, COLOR_WHITE, COLOR_BLACK);

    while (1) {
        clear();
        timeout(1);
        int key = getch();
        if (key == 'q')
            break;
        mvprintw(2, 2, "Hello World!");
        refresh();
    }
    erase();
    endwin();
}