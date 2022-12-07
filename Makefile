SERVER_SRC	= server.c ascii.c
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_SRC	= client.c
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
HEADERS		= minitalk.h

all:		libft server client

%.o: %.c ${HEADERS} libft/libft.a
			${CC} $< -c -o $@

libft:
			@make -C libft

server:		${SERVER_OBJS} ${HEADERS}
			cc -Wall -Werror -Wextra ${SERVER_OBJS} -Llibft -lft -o server

client:		${CLIENT_OBJS} ${HEADERS}
			cc -Wall -Werror -Wextra ${CLIENT_OBJS} -Llibft -lft -o client

clean:
			rm -rdf ${SERVER_OBJS} ${CLIENT_OBJS}
			@make clean -C libft

fclean:		clean
			rm -rdf client server
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re server client 
