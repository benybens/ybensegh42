HEADERDIR = ./
SRCSDIR = ./
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS  = ${addprefix ${SRCSDIR}, ft_isalpha.c  ft_strlen.c ft_isdigit.c ft_isalnum.c}
SRCS  += ${addprefix ${SRCSDIR}, ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c}
SRCS  += ${addprefix ${SRCSDIR}, ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_memset.c}
SRCS  += ${addprefix ${SRCSDIR}, ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c}
SRCS  += ${addprefix ${SRCSDIR}, ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c}
SRCS  += ${addprefix ${SRCSDIR}, ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c}
SRCS  += ${addprefix ${SRCSDIR}, ft_strrev.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c}
SRCS  += ${addprefix ${SRCSDIR}, ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c}
OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all: ${NAME}

test:	
	${CC} ${CFLAGS} -o libft_test main.c -L/. libft.a
	./libft_test


clean:
		rm -rf ${OBJS}
	
fclean:		clean
		rm -rf ${NAME}

re:		fclean all

.PHONY:		all re clean fclean
