CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
NAME = fdf
LIBMLX = ./libs/libmlx.a
LIBFT = ./libs/libft.a
HEADERDIR = ./includes
SRCS = main.c ./srcs/fdf/controller.c ./srcs/fdf/image_utils.c ./srcs/fdf/map_utils.c ./srcs/fdf/points_manager.c
OBJS = ${SRCS:.c=.o}

.c.o:	
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			make -C ./srcs/libft
			make -C ./srcs/minilibx_macos
			cp ./srcs/libft/libft.a ${LIBFT}
			cp ./srcs/minilibx_macos/libmlx.a ${LIBMLX}
			${CC} ${CFLAGS} -framework OpenGL -framework AppKit -o ${NAME} ${SRCS}  -L ./ ${LIBFT} ${LIBMLX}

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

