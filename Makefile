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
	make clean -C core/
	make clean -C games/
	make clean -C lib/

fclean:
	make fclean -C core/
	make fclean -C games/
	make fclean -C lib/
	$(RM) arcade
	$(RM) *.so

re:	fclean all

.SILENT:
