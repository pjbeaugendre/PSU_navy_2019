##
## EPITECH PROJECT, 2019
## PSU_minishell1_2019
## File description:
## Makefile
##

SRC	=	src/errors/file_error.c\
		src/errors/error_boats.c\
		src/init.c\
		src/play1.c\
		src/play2.c\
		src/navy.c\
		src/connect.c\
		src/send.c\
		src/receive.c\
		src/utils.c\
		src/main.c

OBJ		=	$(SRC:.c=.o)

NAME	= 	navy

CFLAGS = -I./include -Wall -Wextra

LIB_PATH = ./lib

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C lib/my
	gcc $(OBJ) -g -o $(NAME) -L$(LIB_PATH) -lmy

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
