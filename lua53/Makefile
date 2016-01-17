##
## Makefile for gomoku in /home/bevill_a/rendu/Gomoku/lua53
## 
## Made by Alexis Bevillard
## Login   <bevill_a@epitech.net>
## 
## Started on  Sun Jan 17 11:31:27 2016 Alexis Bevillard
## Last update Sun Jan 17 11:33:47 2016 Alexis Bevillard
##

NAME =		test_lua

GR_SRC_DIR =	src/
GOBJ_DIR =	objs/
GR_INC_DIR =	inc/
LUA_LIB_DIR =	lua-5.3.2/lib/
LUA_INC_DIR =	lua-5.3.2/include/

GR_SRCS =	$(GR_SRC_DIR)test.cpp \

GR_OBJS =	$(patsubst $(GR_SRC_DIR)%, $(GOBJ_DIR)%, $(GR_SRCS:.cpp=.o))

CPPFLAGS +=	-I$(LUA_INC_DIR)
CPPFLAGS +=	-O3 -Wall -Wextra -W -g3 -std=c++11

GR_LDFLAGS +=	-L$(LUA_LIB_DIR) -llua53

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
