NAME = 		minitalk

SRCS = 		funcs.c
CLINET = 	client.c
SERVER = 	server.c
HEADER = 	minitalk.h

OBJS = ${patsubst %.c, %.o, ${SRCS}}
CLINET_OBJ = ${patsubst %.c, %.o, ${CLINET}}
SERVER_OBJ = ${patsubst %.c, %.o, ${SERVER}}

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: client server

client: ${CLINET_OBJ} ${OBJS}
	gcc ${CLINET_OBJ} ${OBJS} -o $@ -I ${HEADER}

server: ${SERVER_OBJ}
	gcc ${SERVER_OBJ} ${OBJS} -o $@ -I ${HEADER}

%.o: %.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

bonus: all

clean:
	rm -f *.o *.g.gch

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re bonus