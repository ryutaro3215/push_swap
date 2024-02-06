NAME = push_swap
MSRC = push_swap.c check.c int_check.c finish.c init_stack.c swap.c rotate.c r_rotate.c push.c \
sort.c sort_two.c keep.c sort_three.c
OBJS = $(MSRC:.c=.o)
LIB_DIR = libft
LIB = ft
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(LIB_DIR)/includes
LIBRARY = -L $(LIB_DIR) -l $(LIB)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBRARY) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB_DIR)/*.o

fclean: clean
	rm -f $(NAME) $(LIB_DIR)/*.a

re: fclean all

.PHONY: clean fclean re all
