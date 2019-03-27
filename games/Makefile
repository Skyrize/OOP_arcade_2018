##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

RM			=	rm -rf

_END=$'\x1b[0m'
_RED=$'\x1b[31m'
NO_OF_FILES := $(words $(SRC))

all:	prepare_lib

prepare_lib:
	make -C pacman/
	cp pacman/*.so ./
	make -C nibbler/
	cp nibbler/*.so ./

clean:
	make clean -C pacman/
	make clean -C nibbler/

fclean:
	make fclean -C pacman/
	make fclean -C nibbler/
	$(RM) ./*.so

re:	fclean all

.SILENT:
