##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CXXFLAGS	=	--std=c++11 -shared -W -Wall -Wextra -Werror -I../../include -I./include  -g3 -fPIC
CC 			= 	g++

SRC			=	src/main.cpp	\
				src/SDL2.cpp	\

OBJ			=	$(SRC:.cpp=.o)

NAME		=	lib_arcade_sdl2.so

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ) `sdl2-config --cflags --libs`

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	find . -name "*.gcda" -type f -delete
	find . -name "*.html" -type f -delete
	find . -name "*.gcno" -type f -delete

re:	fclean all
