##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

RM			=	rm -rf

all:	graphicals games core

core:
	make -C core/
	cp core/arcade ./

games:
	make -C games/
	cp games/*.so ./

graphicals:
	make -C lib/
	cp lib/*.so ./

clean:
	make clean core/
	make clean games/
	make clean lib/

fclean:
	make fclean core/
	make fclean games/
	make fclean lib/
	$(RM) arcade
	$(RM) *.so

re:	fclean all

.SILENT:
