CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = ./libft/libft.a
SRCSDIR = ./srcs/
HEADERDIR = ./includes
SRCS = ${addprefix ${SRCSDIR}, ft_printf.c}
OBJS = ${SRCS:.c=.o}

.c.o:	
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}


${NAME}:	${OBJS} ${LIBFT}
		ar rcT ${NAME} ${OBJS}
		ar crsT ${NAME} ${LIBFT}
		ranlib ${NAME}

all:	${NAME}
	
test:	${NAME}
	${CC} ${CFLAGS} -o libftprintf main.c -L/. libftprintf.a
	./libftprintf.exe

clean: 
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all fclean clean re test

