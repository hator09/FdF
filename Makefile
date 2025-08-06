
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -Iminilibx-linux
#-Wall -Wextra -Werror
NAME = fdf


SRC = fdf.c utils.c map.c draw_line.c window.c projection.c
OBJ = $(SRC:.c=.o)

MLX_DIR	= minilibx-linux
MLX_LIB	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

