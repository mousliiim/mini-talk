SERVER_SRC	= server.c
CLIENT_SRC	= client.c
HEADERS		= minitalk.h

CC			= cc -Wall -Werror -Wextra
CC_FLAGS	= -Llibft -lft

%.o: %.c ${HEADERS} libft/libft.a
			${CC} $< -c -o $@

all:		libft server client

libft:
			@make -C libft

server:		${SERVER_SRCS:.c=.o} ${HEADERS}
			${CC} ${SERVER_SRC} ${CC_FLAGS} -o server

client:		${CLIENT_SRCS:.c=.o} ${HEADERS}
			${CC} ${CLIENT_SRC} ${CC_FLAGS} -o client

clean:
			rm -rdf ${SERVER_SRC:.c=.o} ${CLIENT_SRC:.c=.o}
			@make clean -C libft

fclean:		clean
			rm -rdf client server
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re