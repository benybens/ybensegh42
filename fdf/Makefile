CC = gcc
CFLAGS = -Wall -Wextra -Werror 
NAME = fdf
LIBMLX = ./libs/libmlx.a
LIBFT = ./libs/libft.a
HEADERDIR = ./includes
SRCS = main.c
OBJS = ${SRCS:.c=.o}

.c.o:	
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			make -C ./srcs/libft
			make -C ./srcs/minilibx_macos
			cp ./srcs/libft/libft.a ${LIBFT}
			cp ./srcs/minilibx_macos/libmlx.a ${LIBMLX}
			${CC} ${CFLAGS} -framework OpenGL -framework AppKit -o ${NAME} ${SRCS} -L ./ ${LIBFT} ${LIBMLX}

all:	${NAME}
	
clean: 
		make -C ./srcs/libft clean
		rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}
	rm ${LIBFT}
	rm ${LIBMLX}
	make -C ./srcs/libft fclean
	make -C ./srcs/minilibx_macos clean

re: fclean ${NAME}

.PHONY: all fclean clean re test

