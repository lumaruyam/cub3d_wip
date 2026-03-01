
NAME = cub3D

CC = cc
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
SRC =	init/init_mlx.c init/init_textures.c init/init.c \
		move/input_handler.c move/player_dir.c move/player_move.c move/player_pos.c move/player_rotate.c \
		render/raycasting.c render/render.c render/texture.c \
		exit/exit.c exit/free_data.c \
		parsing/check_file.c parsing/color_textures.c parsing/fil_data.c parsing/map_check.c \
		parsing/parse_data.c parsing/parsing_utils1.c parsing/texture.c parsing/create_map.c \
		error.c utils.c main.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

INC = 	-I ./inc/ \
		-I ./libft/inc/\
		-I ./minilibx-linux/

RM = rm -rf

all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) -lXext -lX11 -lm

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJS))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MLX):
	@make -C $(MLX_PATH)

bonus: all

clean:
	@$(RM) $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all re clean fclean bonus
