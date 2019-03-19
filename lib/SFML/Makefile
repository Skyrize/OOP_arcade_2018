##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CXXFLAGS	=	--std=c++11 -shared -W -Wall -Wextra -Werror -I../../include -I./include  -g3 -fPIC -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system
CC 			= 	g++

SRC			=	src/main.cpp	\
				src/SFML.cpp	\

OBJ			=	$(SRC:.cpp=.o)

NAME		=	lib_arcade_sfml.so

_END=$'\x1b[0m'
_RED=$'\x1b[31m'
NO_OF_FILES := $(words $(SRC))

all:	$(NAME)

$(NAME):	$(OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;35m$(NO_OF_FILES)\033[0m"
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ) -ldl -lsfml-graphics -lsfml-window -lsfml-system
	@ echo "\033[1;31m ------------------Name of Binary : \033[1;35m$(NAME)\033[0;31m®\033[1;31m Created Sucesfully ------------------\033[0m"	

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	find . -name "*.gcda" -type f -delete
	find . -name "*.html" -type f -delete
	find . -name "*.gcno" -type f -delete

re:	fclean all

%.o:	%.cpp
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CXXFLAGS)

.SILENT: