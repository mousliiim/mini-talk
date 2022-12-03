SERVER_SRC	= server.c ascii.c
CLIENT_SRC	= client.c
HEADERS		= minitalk.h

%.o: %.c ${HEADERS} libft/libft.a
			${CC} $< -c -o $@

all:		libft server client

libft:
			@make -C libft

server:		${SERVER_SRC:.c=.o} ${HEADERS}
			cc -Wall -Werror -Wextra ${SERVER_SRC} -Llibft -lft -o server

client:		${CLIENT_SRC:.c=.o} ${HEADERS}
			cc -Wall -Werror -Wextra ${CLIENT_SRC} -Llibft -lft -o client

clean:
			rm -rdf ${SERVER_SRC:.c=.o} ${CLIENT_SRC:.c=.o}
			@make clean -C libft

fclean:		clean
			rm -rdf client server
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re server client ascii
