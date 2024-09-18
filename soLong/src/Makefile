NAME	=	so_long

SRCS	=	main.c \
			get_next_line.c \
			get_next_line_utils.c \
			error.c \
			solve_map.c \
			stack.c \
			map_component_check.c \
			map_create.c \
			map_rectangular_check.c \
			map_wall_check.c \
			mlx_image.c \
			ft_putnbr_fd.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			map_move.c \

OBJS    =    ${SRCS:.c=.o}

CC    =    cc

# CFLAGS    =    -Wall -Wextra -Werror -fsanitize=address
CFLAGS    =    -Wall -Wextra -Werror 

MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit

RM    =    rm -f

all:${NAME}

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	${RM} ${OBJS} 
fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY:
	all clean fclean re 
