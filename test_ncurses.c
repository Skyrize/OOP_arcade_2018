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

    while (1) {
        clear();
        timeout(1);
        int key = getch();
        if (key == 'q')
            break;
        mvprintw(2, 2, int_to_str(COLS));
        mvprintw(3, 3, int_to_str(LINES));
        refresh();
    }
    erase();
    endwin();
}