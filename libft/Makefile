HEADERDIR = ./includes
SRCSDIR = ./srcs/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS  = ${addprefix ${SRCSDIR},ft_isalpha.c  ft_strlen.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c}
OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all: ${NAME}

test:	
	${CC} ${CFLAGS} -o libft_test main.c -L/. libft.a
	./libft_test.exe

clean:
		rm -rf ${OBJS}
	
fclean:		clean
		rm -rf ${NAME}

re:		fclean all

.PHONY:		all re clean fclean
