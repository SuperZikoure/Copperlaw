##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
DEFAULT_C	=	"\e[39m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

COLOR_THEME	=	$(MAGEN_C)
DEBUG_THEME	=	$(CYAN_C)

NAME	=	graph
SRC_PATH	=	./src
INCLUDE_PATH	=	../include

SRC	=	manage_anim.c	\
		manage_image.c	\
		manage_input.c	\
		manage_music.c	\
		manage_sound.c	\
		manage_text.c	\
		manage_window.c

SRCS	=	$(SRC:%=$(SRC_PATH)/%)
OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I $(INCLUDE_PATH)
DEBUG_FLAGS	=	-g3 -gdwarf-4

all:	$(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  ____                 _     "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" / ___|_ __ __ _ _ __ | |__  "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |  _| '__/ _\` | '_ \| '_ \ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |_| | | | (_| | |_) | | | |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" \____|_|  \__,_| .__/|_| |_|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"                |_|          "$(DEFAULT)
	@$(LINE_RETURN)

$(NAME):	$(OBJ)
	@ar rc ./lib$(NAME).a $(OBJ)
	# && \
	#	$(ECHO) $(BOLD_T)$(GREEN_C)"[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "lib$(NAME).a" $(DEFAULT) || \
	#	$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "lib$(NAME).a"$(DEFAULT)

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"lib$(NAME)'s object files"$(DEFAULT)

fclean:	clean
	@$(RM) ./lib$(NAME).a
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary lib$(NAME).a"$(DEFAULT)

re:		fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(DEBUG_THEME)
debug: all

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) message clean fclean re debug
