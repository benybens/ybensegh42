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
			make -C ft_printf
			cp ./ft_printf/libftprintf.a ${LIBPRINTF}
			${CC} ${CFLAGS} -framework OpenGL -framework AppKit -o ${NAME} main.c -L ./ ${LIBPRINTF} ${LIBMLX}

all:	${NAME}
	
clean: 
		make -C ft_printf clean
		rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}
	rm ${LIBPRINTF}

re: fclean ${NAME}

.PHONY: all fclean clean re test

