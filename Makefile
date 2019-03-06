##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

RM			=	rm -rf

all:	graphicals games core

core:
	make -C arcade/
	cp arcade/arcade ./

games:
	make -C games/
	cp games/*.so ./

graphicals:
	make -C lib/
	cp lib/*.so ./

clean:
	make clean arcade/
	make clean games/
	make clean lib/

fclean:	clean
	$(RM) arcade
	$(RM) *.so

re:	fclean all

.SILENT:
