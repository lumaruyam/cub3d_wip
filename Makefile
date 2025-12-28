
NAME = cub3d

# BONUS = 0 /*remove comment if we will do bonus" */

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

SRC_PATH = ./src/
SRC = 	main.c error.c utils.c \
		init/init_mlx.c init/init_textures.c init/init.c \
		move/input_handler.c move/palyer_dir.c move/player_move.c move/player_pos.c move_player_rotate.c \
		render/raycasting.c render/render.c render/texture.c \
		exit/exit.c exit/free_data.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

INC = 	-I ./inc/ \
		-I ./libft/\
		-I ./minilibx-linux/

RM = rm -rf

all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm
# 	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

$(LIBFT):
	@make -C (LIBFT_PATH)

$(MLX):
	@make -C (MLX_PATH)

# bonus:
# 	make all BONUS=1

clean:
	@$(RM) $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all re clean fclean
