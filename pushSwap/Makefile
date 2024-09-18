NAME	=	push_swap

SRCS	=	bubble_sort.c \
			debug_print.c \
			error.c \
			ft_atoi.c \
			ft_memcpy.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			io.c \
			libft_utils.c \
			make_compress.c \
			make_input.c \
			make_nums.c \
			make_list.c \
			rules_a.c \
			rules_b.c \
			optimize_sort_a.c \
			optimize_sort_b.c \
			push_swap_sort.c \
			search.c \

OBJS    =    ${SRCS:.c=.o}

CC    =    cc

CFLAGS    =    -Wall -Wextra -Werror -fsanitize=address

RM    =    rm -f

all:${NAME}

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	${RM} ${OBJS} 
fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY:
	all clean fclean re 
