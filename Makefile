##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC			=	src/main.cpp	\

OBJ			=	$(SRC:.cpp=.o)

NAME		=	arcade

CXXFLAGS	=	 -Wall -Wextra -Werror

CC			=	g++ -I./include/ --std=c++11 -g

RM			=	rm -rf

_END=$'\x1b[0m'
_RED=$'\x1b[31m'
NO_OF_FILES := $(words $(SRC))

all:	$(NAME)

$(NAME):	graphicals core

core:	$(OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;35m$(NO_OF_FILES)\033[0m"
	$(CC) -o $(NAME) $(OBJ)
	@ echo "\033[1;31m ------------------Name of Binary : \033[1;35m$(NAME)\033[0;31m®\033[1;31m Created Sucesfully ------------------\033[0m"

games:
	make -C games

graphicals:
	make -C lib/libcaca
	make -C lib/SFML
	make -C lib/nCurses	

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

%.o:	%.cpp
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CXXFLAGS)

.SILENT:
