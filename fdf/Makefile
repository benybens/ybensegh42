CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
LIBMLX = ./libmlx.a
LIBPRINTF = ./libftprintf.a
HEADERDIR = ./
SRCS = main.c
OBJS = ${SRCS:.c=.o}

.c.o:	
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} main.c -L ./ ${LIBPRINTF} ${LIBMLX}

all:	${NAME}
	
clean: 
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all fclean clean re test
