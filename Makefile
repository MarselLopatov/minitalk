NAME = 		minitalk

SRCS = 		funcs.c
CLINET = 	client.c
SERVER = 	server.c
HEADER = 	minitalk.h

SRCS_BONUS = 	funcs_bonus.c
CLINET_BONUS = 	client_bonus.c
SERVER_BONUS = 	server_bonus.c
HEADER_BONUS = 	minitalk_bonus.h

OBJS = ${patsubst %.c, %.o, ${SRCS}}
CLINET_OBJ = ${patsubst %.c, %.o, ${CLINET}}
SERVER_OBJ = ${patsubst %.c, %.o, ${SERVER}}

OBJS_BONUS = ${patsubst %.c, %.o, ${SRCS_BONUS}}
CLINET_OBJ_BONUS = ${patsubst %.c, %.o, ${CLINET_BONUS}}
SERVER_OBJ_BONUS = ${patsubst %.c, %.o, ${SERVER_BONUS}}

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: client server

bonus: client_bonus server_bonus

client: ${CLINET_OBJ} ${OBJS}
	gcc ${CLINET_OBJ} ${OBJS} -o $@ -I ${HEADER}

server: ${SERVER_OBJ} ${OBJS}
	gcc ${SERVER_OBJ} ${OBJS} -o $@ -I ${HEADER}

client_bonus: ${CLINET_OBJ_BONUS} ${OBJS_BONUS}
	gcc ${CLINET_OBJ_BONUS} ${OBJS_BONUS} -o $@ -I ${HEADER_BONUS}

server_bonus: ${SERVER_OBJ_BONUS} ${OBJS_BONUS}
	gcc ${SERVER_OBJ_BONUS} ${OBJS_BONUS} -o $@ -I ${HEADER_BONUS}

%.o: %.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

clean:
	rm -f *.o *.g.gch

fclean: clean
	rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re bonus