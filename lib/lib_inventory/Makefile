##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile lib_inv
##

DEFAULT         =       "\e[0m"
BOLD_T          =       "\e[1m"
DIM_T           =       "\e[2m"
UNDLN_T         =       "\e[4m"
BLACK_C         =       "\e[30m"
RED_C           =       "\e[31m"
GREEN_C         =       "\e[32m"
YELLO_C         =       "\e[33m"
BLUE_C          =       "\e[34m"
MAGEN_C         =       "\e[35m"
CYAN_C          =       "\e[36m"
WHITE_C         =       "\e[97m"
DEFAULT_C       =       "\e[39m"
LIGHT_GREY      =       "\e[37m"
DARK_GREY       =       "\e[90m"
LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLO     =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGEN     =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"
ECHO            =       /bin/echo -e

NAME	=	libinv.a

SRC	=	src/tools/tri_inventory.c	\
		src/tools/stack_item.c	\
		src/tools/get_id.c	\
		src/tools/get_all_id.c	\
		src/tools/flood_inventory.c	\
		src/tools/check_index.c	\
		src/tools/add_in_new_stack.c	\
		src/add_item.c		\
		src/add_item_with_index.c	\
		src/create_inventory.c	\
		src/delete_item.c		\
		src/delete_item_with_index.c	\
		src/get_amount.c		\
		src/remplace_item.c	\
		src/remplace_item_with_index.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I ../../include/

CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE)

all:	$(NAME)

mk_message:
	@$(ECHO) $(BOLT_T)$(WHITE_C)"[LIB INVENTORY]\n"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(YELLO_C)".___                           __\n|   | _______  __ ____   _____/  |_  ___________ ___.__.\n|   |/    \  \/ // __ \ /    \   __\/  _ \_  __ <   |  |\n|   |   |  \   /\  ___/|   |  \  | (  <_> )  | \/\___  |\n|___|___|  /\_/  \___  >___|  /__|  \____/|__|   / ____|\n         \/          \/     \/                   \/\n"$(DEFAULT)
	@$(ECHO) $(LIGHT_GREEN)"Compilated.\n"$(DEFAULT)

$(NAME):	mk_message $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f \#*\#
	@rm -f *~

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean re all
.SILENT: $(OBJ)
