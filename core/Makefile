##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC			=	src/main.cpp	\
				src/Arcade.cpp	\
				src/DLLoader.cpp	\
				src/MenuModule.cpp	\
				src/MainMenuScene.cpp	\
				../src/Scene.cpp	\
				../src/Object.cpp	\
				../src/Text.cpp	\
				../src/MovementComponent.cpp	\
				../src/AnimationComponent.cpp	\
				src/Invader.cpp	\
				src/ShootComponent.cpp	\
				src/Projectile.cpp	\
				src/Button.cpp	\
				src/MovingButton.cpp	\
				src/Star.cpp	\

OBJ			=	$(SRC:.cpp=.o)

NAME		=	arcade

CXXFLAGS	=	 -Wall -Wextra -Werror -I../include/ -I./include/ --std=c++11 -g3

CC			=	g++

RM			=	rm -rf

_END=$'\x1b[0m'
_RED=$'\x1b[31m'
NO_OF_FILES := $(words $(SRC))

all:	$(NAME)

$(NAME):	$(OBJ)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;35m$(NO_OF_FILES)\033[0m"
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ) -ldl
	@ echo "\033[1;31m ------------------Name of Binary : \033[1;35m$(NAME)\033[0;31m®\033[1;31m Created Sucesfully ------------------\033[0m"	

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

%.o:	%.cpp
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CXXFLAGS)

.SILENT:
