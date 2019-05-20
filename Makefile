##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/my_sh.c			\
		src/my_check.c			\
		src/my_str_clean.c		\
		src/my_str_all.c		\
		src/my_paths.c			\
		src/my_numb_of.c		\
		src/my_parsers.c		\
		src/my_env_manage.c		\
		src/my_setenv_manage.c		\
		src/my_unsetenv_manage.c	\
		src/my_cd_manage.c		\
		src/my_setenv_one_arg.c		\
		src/my_setenv_check.c		\
		src/my_setenv_two_arg.c		\
		src/my_setenv_arg_check.c	\
		src/my_exec.c			\
		src/my_exit_check.c		\
		src/my_detect.c			\
		src/my_exec_dot.c		\
		src/my_cd_normer.c		\

OBJ	=	$(SRC:.c=.o)

LIB	=	lib/libgnl.a

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -I./include

CC	=	gcc

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)	\
	rm -rf *~
	rm -rf *.a

re: clean all

.PHONY: all re clean fclean
