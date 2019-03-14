##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CXXFLAGS	=	--std=c++11 -shared -W -Wall -Wextra -Werror -I../../include -I./include -fPIC -g3

CC 			= 	g++

SRC			=	src/main.cpp	\
				src/Snake.cpp	\
				src/SnakeScene.cpp	\
				src/SnakePart.cpp	\
				src/SnakeTail.cpp	\
				src/SnakeModule.cpp	\
				../../src/Object.cpp	\
				../../src/AnimationComponent.cpp	\
				../../src/MovementComponent.cpp	\
				../../src/Scene.cpp	\

OBJ			=	$(SRC:.cpp=.o)

NAME		=	lib_arcade_snake.so

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	find . -name "*.gcda" -type f -delete
	find . -name "*.html" -type f -delete
	find . -name "*.gcno" -type f -delete

re:	fclean all
