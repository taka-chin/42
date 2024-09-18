NAME	=	minitalk

SRCS	=	server.c \
			client.c \

OBJS    =    ${SRCS:.c=.o}

CC    =    cc

CFLAGS    =    -Wall -Wextra -Werror

RM    =    rm -f

SERVER	=	server
SERVER_OBJ	=	server.o

CLIENT	=	client
CLIENT_OBJ	=	client.o

LIBFT	=	libft
LIBFT_A		=	$(LIBFT)/libft.a

all:${NAME}

$(NAME):$(CLIENT) $(SERVER)

$(CLIENT):$(CLIENT_OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT_A) -o $(CLIENT)

$(SERVER):$(SERVER_OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT_A) -o $(SERVER)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	${RM} ${SERVER_OBJ} ${CLIENT_OBJ} $(LIBFT)/*.o $(LIBFT)/*.a
fclean:clean
	${RM} ${CLIENT} ${SERVER}

re:fclean all

.PHONY:
	all clean fclean re 
