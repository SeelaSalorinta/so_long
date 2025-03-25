NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux

MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git

INCLUDES = -I./ -I$(MINILIBX_DIR) -I$(LIBFT_DIR)

MINILIBX = $(MINILIBX_DIR)/libmlx.a

LIBS = -L$(MINILIBX_DIR) -lmlx -L/opt/X11/lib -lX11 -lXext

SRCS = srcs/so_long.c \
       srcs/check_path.c \
       srcs/move_player.c \
       srcs/load_map.c \
       srcs/validate_map.c \
       srcs/exit_free.c \
       srcs/render_map.c \

OBJS = $(SRCS:.c=.o)

all: $(MINILIBX) $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_SRCS)
	@make -C $(LIBFT_DIR)

$(MINILIBX_DIR)/libmlx.a:
	if [ ! -d "$(MINILIBX_DIR)" ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi
	@make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MINILIBX) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
