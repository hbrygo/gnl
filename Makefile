SRCS    =	
OBJS    = ${SRCS:.c=.o}
INCS    = includes
NAME    = get_next_line.a
LIBC    = ar rc
LIBR    = ranlib
CC        = gcc
RM        = rm -f
CFLAGS    = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

compile:
	${CC} -fsanitize=address -g ${SRCS} && ./a.out

re: fclean all
