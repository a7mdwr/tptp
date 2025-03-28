NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra 
CC = cc

SRCS = main.c push.c swap.c utils.c rev_moves.c utils2.c utils3.c do_moves.c silent_moves.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	cd $(LIBFT_DIR) && make clean
	rm -f $(OBJS)

fclean: clean
	cd $(LIBFT_DIR) && make fclean
	rm -f $(NAME) $(LIBFT)

re: fclean all
