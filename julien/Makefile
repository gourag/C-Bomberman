##
## Makefile for  in /home/lacaze_p/rendu/cpp_bomberman/GDLBomber
## 
## Made by Lacazedieu
## Login   <lacaze_p@epitech.net>
## 
## Started on  Tue May  6 13:01:15 2014 Lacazedieu
## Last update Wed May 21 10:34:31 2014 blondeel julien
##

NAME		=	bomber
EDITORNAME	=	bomber_editor

SRC	=	main.cpp \
		classes/GameEngine.cpp \
		classes/AObject.cpp \
		classes/ACharacter.cpp \
		classes/Cube.cpp \
		classes/Audio.cpp \
		classes/ABomb.cpp \
		classes/Player.cpp \
		classes/Thread.cpp \
		classes/AEntity.cpp \
		classes/MapEditor.cpp \
		classes/Case.cpp \
		classes/Map.cpp \
		classes/Serialize.cpp \
		classes/MyException.cpp \
		classes/Loader.cpp \
		classes/AEntityFactory.cpp \
		classes/Folder.cpp \

SRCEDITOR=	mainEditor.cpp \
		classes/GameEngine.cpp \
		classes/AObject.cpp \
		classes/ACharacter.cpp \
		classes/Cube.cpp \
		classes/Audio.cpp \
		classes/ABomb.cpp \
		classes/Player.cpp \
		classes/Thread.cpp \
		classes/AEntity.cpp \
		classes/MapEditor.cpp \
		classes/Case.cpp \
		classes/Map.cpp \
		classes/Serialize.cpp \
		classes/MyException.cpp \
		classes/Loader.cpp \
		classes/AEntityFactory.cpp \
		classes/Folder.cpp \


OBJ	=	$(SRC:.cpp=.o)
OBJEDITOR	=	$(SRCEDITOR:.cpp=.o)

CC	=	g++

INC	=	-I./includes/ -I./fmod/api/inc -I./classes

LDFLAGS	=	-L./libs/ -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -L./fmod/api/lib -lfmodex64 -ldl

CPPFLAGS=	-W -Wall -Wextra $(INC) -g3

all	:	$(NAME) $(EDITORNAME)

$(NAME)	:	$(OBJ)
		@echo "Compiling bomber"
		$(CC) -Wl,-rpath="./libs/" -Wl,-rpath="./fmod/api/lib" -o $(NAME) $(OBJ) $(LDFLAGS)

$(EDITORNAME)	:	$(OBJEDITOR)
		@echo "Compiling bomber, map editor"
		$(CC) -Wl,-rpath="./libs/" -Wl,-rpath="./fmod/api/lib" -o $(EDITORNAME) $(OBJEDITOR) $(LDFLAGS)

clean	:
		rm -f $(OBJ)
		rm -f $(OBJEDITOR)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(EDITORNAME)

re	:	fclean all

.PHONY	:	all clean fclean re
