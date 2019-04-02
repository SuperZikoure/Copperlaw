##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile lib
##

NAME	:=	libfile.a

SRC	:=	src/create_and_write_file.c	\
		src/file_create.c	\
		src/write_file.c	\
		src/close_dir.c		\
		src/close_file.c	\
		src/free_dirinf.c	\
		src/free_fileinf.c	\
		src/init_dirinf.c	\
		src/init_fileinf.c	\
		src/init_stat.c		\
		src/open_dir.c		\
		src/open_file.c		\
		src/read_dir.c		\
		src/read_file.c		\
		src/is_dir.c		\
		src/check_access.c

OBJ	:=	$(SRC:.c=.o)

INCLUDE	:=	-I ../../include/

CFLAGS	:=	$(INCLUDE)

all:	$(NAME)

$(NAME):	$(OBJ)
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
