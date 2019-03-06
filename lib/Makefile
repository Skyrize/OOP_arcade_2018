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
	make -C libcaca/
	cp libcaca/*.so ./
	make -C nCurses/
	cp nCurses/*.so ./
	make -C SFML/
	cp SFML/*.so ./

clean:
	make clean -C libcaca/
	make clean -C nCurses/
	make clean -C SFML/

fclean:
	make fclean -C libcaca/
	make fclean -C nCurses/
	make fclean -C SFML/
	$(RM) ./*.so

re:	fclean all

.SILENT:
