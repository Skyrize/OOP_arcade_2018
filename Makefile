##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

RM			=	rm -rf

all:	graphicals games core

.PHONY:	core
core:
	make -C core/
	cp core/arcade ./

.PHONY:	games
games:
	make -C games/

graphicals:
	make -C lib/

clean:
	make clean -C core/
	make clean -C games/
	make clean -C lib/

fclean:
	make fclean -C core/
	make fclean -C games/
	make fclean -C lib/
	$(RM) arcade

re:	fclean all

.SILENT:
