/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** test_ncurses
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *int_to_str(int nb)
{
	char *str;
	int i = 1;
	int j = 0;
	int tmp = nb;

	while (tmp > 9) {
		tmp /= 10;
		i++;
	}
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	j = i;
	while (i > 0) {
		str[i - 1] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	str[j] = '\0';
	return (str);
}

int main(void)
{
    initscr();
    curs_set(0);
	noecho();
	WINDOW *win = newwin(0, 0, 0, 0);
	nodelay(win, true);
	keypad(win, true);

    while (1) {
        werase(win);
        int key = wgetch(win);
        if (key == 'q')
            break;
        wrefresh(win);
    }
    werase(win);
	delwin(win);
    endwin();
}