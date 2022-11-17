CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
LIBFT = ./libft/libft.a
SRCSDIR = ./srcs/
HEADERDIR = ./includes
SRCS = ${addprefix ${SRCSDIR}, ft_printf.c}
OBJS = ${SRCS:.c=.o}

.c.o:	
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			make -C libft
			cp ${LIBFT} .
			mv libft.a libftprintf.a
			ar rcs ${NAME} ${OBJS}
all:	${NAME}
	
test:	${NAME}
	${CC} ${CFLAGS} -o libftprintf main.c -L/. libftprintf.a
#	${CC} ${CFLAGS} -o libftprintf main.c ./srcs/ft_printf.c -L/. libftprintf.a
	./libftprintf

clean: 
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all fclean clean re test

