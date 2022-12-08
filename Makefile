SERVER_SRC	= server.c ascii.c
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_SRC	= client.c
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
HEADERS		= minitalk.h

CC			= cc -Wall -Werror -Wextra
CC_FLAGS 	= -Llibft -lft

all:		libft server client

%.o: %.c ${HEADERS} libft/libft.a
			${CC} $< -c -o $@

libft:
			@make -C libft

server:		${SERVER_OBJS} ${HEADERS}
			${CC} ${SERVER_OBJS} ${CC_FLAGS} -o server

client:		${CLIENT_OBJS} ${HEADERS}
			${CC} ${CLIENT_OBJS} ${CC_FLAGS} -o client

clean:
			rm -rdf ${SERVER_OBJS} ${CLIENT_OBJS}
			@make clean -C libft

fclean:		clean
			rm -rdf client server
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re
