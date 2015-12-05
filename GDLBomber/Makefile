##
## Makefile for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
## 
## Made by Lacazedieu
## Login   <lacaze_p@epitech.net>
## 
## Started on  Tue May  6 13:01:15 2014 Lacazedieu
## Last update Fri May  9 10:36:40 2014 jonathan
##

NAME	=	GDL

SRC	=	test.cpp \
		GameEngine.cpp \
		Cube.cpp \
		AObject.cpp \
		Hero.cpp \

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

INC	=	-I./includes/

LDFLAGS	=	-L./libs/ -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread

CPPFLAGS=	-W -Wall $(INC)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -Wl,-rpath="./libs/" -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
