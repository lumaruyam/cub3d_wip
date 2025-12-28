
NAME = cub3d

BONUS = 0

CC = gcc
CFLAGS = -Werror -Wextra -Wall -g3

# Minilibx
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

#Libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)
