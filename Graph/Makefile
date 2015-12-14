##
## Makefile for Makefile in /home/trupin_t/rendu/tuto
## 
## Made by Thomas Trupin
## Login   <trupin_t@epitech.net>
## 
## Started on Wed Jul  8 17:01:06 2015 Thomas Trupin
## Last update Fri Dec 11 18:22:10 2015 Thomas Trupin
##

NAME =		gomoku

GR_SRC_DIR =	src/
GOBJ_DIR =	objs/
GR_INC_DIR =	inc/
SFML_LIB_DIR =	SFML-2.2/lib/
GLEW_LIB_DIR =	glew-1.10.0/lib/
SFML_INC_DIR =	SFML-2.2/include/
GLEW_INC_DIR =	glew-1.10.0/include/

GR_SRCS =	$(GR_SRC_DIR)main.cpp \
		$(GR_SRC_DIR)GameStateStart.cpp \
		$(GR_SRC_DIR)GameStateOver.cpp \
		$(GR_SRC_DIR)GameStateMenu.cpp \
		$(GR_SRC_DIR)Game.cpp \
		$(GR_SRC_DIR)TextureManager.cpp \
		$(GR_SRC_DIR)Tile.cpp \
		$(GR_SRC_DIR)Arbiter.cpp \

GR_OBJS =	$(patsubst $(GR_SRC_DIR)%, $(GOBJ_DIR)%, $(GR_SRCS:.cpp=.o))

LDFLAGS =	-lm

CPPFLAGS +=	-I$(GR_INC_DIR) -I$(GLEW_INC_DIR) -I$(SFML_INC_DIR) -I$(AUDIO_INC)
CPPFLAGS +=	-O3 -Wall -Wextra -W -g3 -std=c++11

GR_LDFLAGS +=	-L$(GLEW_LIB_DIR) -lGLEW
GR_LDFLAGS +=	-L$(SFML_LIB_DIR) -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window
GR_LDFLAGS +=	-Wl,-rpath=$(GLEW_LIB_DIR):$(SFML_LIB_DIR):$(AUDIO_LIB)

CPP_COMPILE =	g++ -c
CPP_LINK =	g++ -o
MKDIR =		mkdir -p
RM =		rm -rfv
ECHO_GREEN =	echo -e "\033[32m"
END_OF_ECHO =	"\033[0m"
CP =		cp

all:		$(NAME)

$(GOBJ_DIR)%.o:	$(GR_SRC_DIR)%.cpp
		@$(MKDIR) $(dir $@)
		@$(CPP_COMPILE) $< $(CPPFLAGS) -o $@
		@echo $(patsubst $(GR_SRC_DIR)%, %, $<) compiled

$(NAME):	$(GR_OBJS)
		@$(CPP_LINK) $(NAME) $(GR_OBJS) $(GR_LDFLAGS)
		@$(ECHO_GREEN)[OK] $(NAME) linked $(END_OF_ECHO)


clean:
		@$(RM) $(GOBJ_DIR)
		@$(ECHO_GREEN)[OK] Every objects have been removed $(END_OF_ECHO)

fclean:		clean
		@$(RM) $(NAME)
		@$(ECHO_GREEN)[OK] $(NAME) removed $(END_OF_ECHO)

re:		fclean all

.PHONY:		all clean fclean re
