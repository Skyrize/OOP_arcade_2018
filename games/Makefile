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
	make -C insert_game_folder/
	cp insert_game_folder/*.so ./

clean:
	make clean insert_game_folder/

fclean:	clean
	$(RM) ./*.so

re:	fclean all

.SILENT:
