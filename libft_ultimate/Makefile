CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
LIBFT = ./libft/libft.a
SRCSDIR = ./srcs/
HEADERDIR = ./includes
SRCS = ./srcs/ft_printf.c ./srcs/ft_process.c ./srcs/ft_process_2.c ./srcs/ft_parse.c ./srcs/ft_convert.c ./srcs/get_next_line.c ./srcs/get_next_line_utils.c 
OBJS = ${SRCS:.c=.o}

.c.o:	
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			make -C libft
			cp ${LIBFT} .
			ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean: 
	make -C libft clean
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all fclean clean re test

