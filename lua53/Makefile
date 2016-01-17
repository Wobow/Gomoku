##
## Makefile for gomoku in /home/bevill_a/rendu/Gomoku/lua53
## 
## Made by Alexis Bevillard
## Login   <bevill_a@epitech.net>
## 
## Started on  Sun Jan 17 11:31:27 2016 Alexis Bevillard
## Last update Sun Jan 17 15:09:36 2016 Alexis Bevillard
##

NAME =		test_lua

SRC_DIR =	src/
OBJ_DIR =	objs/
INC_DIR =	inc/
LUA_LIB_DIR =	lua-5.3.2/lib/
LUA_INC_DIR =	lua-5.3.2/include/

SRCS =		$(SRC_DIR)test.cpp \

OBJS =		$(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRCS:.cpp=.o))

CPPFLAGS +=	-I$(LUA_INC_DIR) -I$(INC_DIR)
CPPFLAGS +=	-O3 -Wall -Wextra -W -g3 -std=c++11

LDFLAGS +=	-L$(LUA_LIB_DIR) -llua53

CPP_COMPILE =	g++ -c
CPP_LINK =	g++ -o
MKDIR =		mkdir -p
RM =		rm -rfv
ECHO_GREEN =	echo -e "\033[32m"
END_OF_ECHO =	"\033[0m"
CP =		cp

all:		$(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
		@$(MKDIR) $(dir $@)
		@$(CPP_COMPILE) $< $(CPPFLAGS) -o $@
		@echo $(patsubst $(SRC_DIR)%, %, $<) compiled

$(NAME):	$(OBJS)
		@$(CPP_LINK) $(NAME) $(OBJS) $(LDFLAGS)
		@$(ECHO_GREEN)[OK] $(NAME) linked $(END_OF_ECHO)


clean:
		@$(RM) $(OBJ_DIR)
		@$(ECHO_GREEN)[OK] Every objects have been removed $(END_OF_ECHO)

fclean:		clean
		@$(RM) $(NAME)
		@$(ECHO_GREEN)[OK] $(NAME) removed $(END_OF_ECHO)

re:		fclean all

.PHONY:		all clean fclean re
