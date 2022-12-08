##
## EPITECH PROJECT, 2022
## fun
## File description:
## Makefile
##

ENGINE	=	src/engine
UTIL	= 	src/Utils
RSR		=	src/ResourceManager
GAME	=	src/Game

SRC		=	src/main.cpp					\
			$(ENGINE)/SoftwareRender.cpp	\
			$(ENGINE)/Camera.cpp			\
			$(ENGINE)/Projection.cpp		\
			$(ENGINE)/Cube.cpp				\
			$(UTIL)/Vec3.cpp				\
			$(UTIL)/FPSCounter.cpp			\
			$(UTIL)/matrix_functions.cpp	\
			$(RSR)/ResourceHolder.cpp		\
			$(GAME)/World.cpp				\
			$(GAME)/Chunk.cpp				\

NAME	=	minecraft

CC		=	g++

RM		=	rm -f

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-Wextra -Wall -Wno-unused-parameter -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
