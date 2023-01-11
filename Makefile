CC = clang
CFLAGS = -I./includes
SRCS = main.c map_parsing.c arg_to_str.c ber_format.c window_free_destroy.c window_init.c \
		path_utils.c valid_path.c dfs.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LFLAGS = -L./libft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
