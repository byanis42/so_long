NAME = so_long
CC = clang
CFLAGS = -I./includes

SRCS_DIR = src
SRCS = main.c map_parsing.c arg_to_str.c ber_format.c window_free_destroy.c window_init.c \
		path_utils.c valid_path.c dfs.c game_init.c

OBJS_DIR = $(SRCS_DIR)/objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LFLAGS = -L./libft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm $(LFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $< \033[0;32m✔\033[0m"
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 $(CFLAGS) -c $< -o $@
$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "===> Objects deleted"

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "===> Binaries deleted"

re: fclean all

.PHONY: all clean fclean re
