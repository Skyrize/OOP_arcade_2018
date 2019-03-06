##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CXXFLAGS	=	-shared -W -Wall -Wextra -Werror -I../../include -I./include -fPIC -g3

CC 			= 	g++

SRC			=	src/main.cpp

OBJ			=	$(SRC:.cpp=.o)

NAME		=	lib_arcade_libcaca.so

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	find . -name "*.gcda" -type f -delete
	find . -name "*.html" -type f -delete
	find . -name "*.gcno" -type f -delete

re:	fclean all
