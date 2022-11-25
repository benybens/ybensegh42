CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
HEADERDIR = ./
SRCS =  get_next_line.c get_next_line.h get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

.c.o:	
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}

all:	${OBJS}
		${CC} ${CFLAGS} -o gnltest main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=1

test:	all
		./gnltest ./test_input/input_text

clean: 
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all fclean clean re test

